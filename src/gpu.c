#include <stdio.h>
#include "gameboy.h"
#include "gpu.h"
#include "memory.h"
#include "errors.h"
#include "interrupts.h"

#define GET_NTH_BIT(n, value) (((value) & (1 << (n))) >> (n))

#warning "IMPROVE PIXEL DRAWING ALGORITHM"

static inline t_pixel_data	to_pixel_data(uint8_t color, uint8_t origin)
{
  return (color | ((origin) << 2));
}

static void		pixel_mixing(t_gameboy *gb, uint8_t priority)
{
  for (unsigned cur = gb->gpu.pff.head, i = 0; i < FETCHED_PIXEL_SIZE; ++i) {
      t_pixel_data const ftch = gb->gpu.fetcher.data[i];
      t_pixel_data const fifo = gb->gpu.pff.fifo[cur];

      if (GET_PD_SOURCE(fifo) == PS_BG && GET_PD_COLOR(ftch) != 0) {
	  if (priority == 0 || (priority == 1 && GET_PD_COLOR(fifo) == 0)) {
	      gb->gpu.pff.fifo[cur] = ftch;
	  }
      }
      cur = (cur + 1) % PIXEL_FIFO_SIZE;
  }
}

static void		push_fetch_to_fifo(t_gameboy *gb)
{
  unsigned const	fb = UPPER_BOUND(PIXEL_FIFO_SIZE - gb->gpu.pff.tail, FETCHED_PIXEL_SIZE);
  unsigned const	sb = FETCHED_PIXEL_SIZE - fb;

  if (PIXEL_FIFO_SIZE - gb->gpu.pff.size < FETCHED_PIXEL_SIZE) {
      perr("No space in FIFO\n");
      return ;
  }
  memcpy(gb->gpu.pff.fifo + gb->gpu.pff.tail, gb->gpu.fetcher.data, fb);
  if (sb) {
      memcpy(gb->gpu.pff.fifo, &gb->gpu.fetcher.data[fb], sb);
  }
  gb->gpu.pff.tail = (gb->gpu.pff.tail + FETCHED_PIXEL_SIZE) % PIXEL_FIFO_SIZE;
  gb->gpu.pff.size += FETCHED_PIXEL_SIZE;
}

static t_pixel_data	pop_from_fifo(t_gameboy *gb)
{
  t_pixel_data	ret = 0;

  /* Keep this guard, for each update of the gpu */
  /*if (gb->gpu.pff.size != 0) {*/
  gb->gpu.pff.size -= 1;
  ret = gb->gpu.pff.fifo[gb->gpu.pff.head];
  gb->gpu.pff.head = (gb->gpu.pff.head + 1) % PIXEL_FIFO_SIZE;
  /*}*/
  /*else {*/
  /*fprintf(stderr, "POP FROM FIFO INVALID\n");*/
  /*}*/
  return (ret);
}

static void	draw_pixel(t_gameboy *gb, int x, int y, uint8_t pixel)
{
  int const width = gb->gpu.display.width;
  int const scale = gb->gpu.display.scale;

  /* Scale x and y */
  x = x * scale;
  y = y * scale;

  for (int i = 0; i < scale; ++i) {
      memset(gb->gpu.pixels + (y * width) + x, pixel, scale);
      y += 1;
  }
}

static inline uint8_t	get_pixel_color(t_gameboy *gb, uint8_t palette, uint8_t value)
{
  return (gb->gpu.display.palette[
	  (palette & (0b11 << (value * 2))) >> (value * 2)]);

}

static inline void	clear_oam(t_gameboy *gb)
{
  memset(&gb->gpu.oam, 0, sizeof(gb->gpu.oam));
}

static inline void	clear_fifo(t_gameboy *gb)
{
  gb->gpu.pff.size = gb->gpu.pff.head = gb->gpu.pff.tail = 0;
}

#warning "TODO: handle flips for oam entries"
/*
** TODO: If this slows down the emulator, do it step by step, by breaking down
** the OAM searching to one call per cycle
*/
static void		oam_search(t_gameboy *gb, uint16_t ln)
{
  uint16_t		address = OAM_INDEX;

  if (!(*gb->hregisters.lcdc & LCDC_OBJ_ENABLE)) {
      return ;
  }
  gb->gpu.oam.index = 0;
  for (unsigned int i = 0; i < OAM_RAM_SIZE; ++i) {
      t_oam_entry const *entry = (t_oam_entry const *)(gb->memory.start + address);

      if (entry->pos_x != 0 && ln + 16 >= entry->pos_y &&
	  ln + 16 < entry->pos_y + GET_SPRITE_HEIGHT(*gb->hregisters.lcdc)) {
	  gb->gpu.oam.array[gb->gpu.oam.index++] = address;
	  if (gb->gpu.oam.index == OAM_ARRAY_MAX) {
	      break ;
	  }
      }
      address += OAM_ENTRY_SIZE;
  }
  t_oam_entry const *entry = (t_oam_entry const *)(gb->memory.start + 0xFE18);

}

static inline uint8_t  *get_bg_tile(t_gameboy *gb, uint8_t tile)
{
  return ((*gb->hregisters.lcdc & LCDC_BGWTD_SELECT) ?
	  (gb->memory.start + CHARACTER_RAM_INDEX + (tile * TILE_SIZE)) :
	  (gb->memory.start + CHARACTER_RAM_INDEX + 0x1000 + ((int8_t)tile * TILE_SIZE)));
}

static inline uint8_t *get_bg_map(t_gameboy *gb)
{
  return ((*gb->hregisters.lcdc & LCDC_BGTM_SELECT) ?
	  (gb->memory.start + BG_MAP_2_INDEX) :
	  (gb->memory.start + BG_MAP_1_INDEX));
}

bool		init_gpu(t_gameboy *gb)
{
  gb->gpu.display.width = SCREEN_WIDTH * gb->gpu.display.scale;
  gb->gpu.display.height = SCREEN_HEIGHT * gb->gpu.display.scale;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.display.screen = SDL_SetVideoMode(gb->gpu.display.width, gb->gpu.display.height, 8,
					    SDL_HWSURFACE | SDL_RESIZABLE);
  if (gb->gpu.display.screen == NULL)
    {
      fprintf(stderr, "SDL_SetVideoMode failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.pixels = gb->gpu.display.screen->pixels;
  gb->gpu.display.palette[0] = SDL_MapRGB(gb->gpu.display.screen->format,
					  0xFF, 0xFF, 0xFF);
  gb->gpu.display.palette[1] = SDL_MapRGB(gb->gpu.display.screen->format,
					  0xAA, 0xAA, 0xAA);
  gb->gpu.display.palette[2] = SDL_MapRGB(gb->gpu.display.screen->format,
					  0x55, 0x55, 0x55);
  gb->gpu.display.palette[3] = SDL_MapRGB(gb->gpu.display.screen->format,
					  0x00, 0x00, 0x00);

  clear_fifo(gb);
  return (0);
}

static inline void	refresh_screen(t_gameboy *gb)
{
  SDL_Flip(gb->gpu.display.screen);
}

static inline void	clear_screen(t_gameboy *gb)
{
  memset(gb->gpu.pixels, 0xFF, gb->gpu.display.width * gb->gpu.display.height);
}

static inline void     compare_lyc(t_gameboy *gb)
{
  if (*gb->hregisters.lyc == *gb->hregisters.ly) {
      *gb->hregisters.stat |= LYC_COINCIDENCE_BIT;
      ask_lcd_stat_interrupt(gb->hregisters._if);
  }
}

static inline void	set_fetcher_address(t_gameboy *gb, uint16_t address)
{
  gb->gpu.fetcher.address = address;
}

static void		fetch_sprite(t_gameboy *gb, t_oam_entry const *entry)
{
  uint8_t		tile_nb = entry->tile;
  uint8_t const		*tile = gb->memory.start + CHARACTER_RAM_INDEX + (tile_nb * TILE_SIZE);
  uint8_t		palette = GET_OAM_PALETTE(entry->flags);
  int16_t const		idx = (((gb->gpu.ppu.y - (entry->pos_y - 16)))) * 2;

  if (idx < 0) {
      printf("WHAT ZE HECK\n");
  }
  uint8_t		data0 = tile[idx];
  uint8_t		data1 = tile[idx + 1];

  for (unsigned i = 0; i < 8; ++i) {
      unsigned const color = (GET_NTH_BIT(7 - i, data1) << 1) | (GET_NTH_BIT(7 - i, data0));
      gb->gpu.fetcher.data[i] = 0;
      gb->gpu.fetcher.data[i] = SET_PD_COLOR(gb->gpu.fetcher.data[i], color);
      gb->gpu.fetcher.data[i] = SET_PD_SOURCE(gb->gpu.fetcher.data[i], PS_OBJ0 + palette);
  }
  pixel_mixing(gb, GET_OAM_PRIORITY(entry->flags));
}

static void		fetcher_step(t_gameboy *gb)
{
  uint8_t		tile_nb = get_bg_map(gb)[gb->gpu.fetcher.address];
  uint8_t const		*tile = get_bg_tile(gb, tile_nb);
  /* Perform (gb->gpu.ppu.y % 8) * 2 */
  uint8_t const		idx = (gb->gpu.ppu.y & 0b111) << 1;
  uint8_t		data0 = tile[idx];
  uint8_t		data1 = tile[idx + 1];

  if (!(*gb->hregisters.lcdc & LCDC_BG_DISPLAY)) {
      data0 = data1 = 0;
  }
  /* Iterate on each pixel and fill fetcher data*/
  for (unsigned i = 0; i < 8; ++i) {
      gb->gpu.fetcher.data[i] = SET_PD_COLOR(0,
					     (GET_NTH_BIT(7 - i, data1) << 1) | (GET_NTH_BIT(7 - i, data0)));
      gb->gpu.fetcher.data[i] = SET_PD_SOURCE(gb->gpu.fetcher.data[i], PS_BG);
  }
  gb->gpu.fetcher.address += 1;
}

static void	ppu_step(t_gameboy *gb)
{
  t_pixel_data	pixel = pop_from_fifo(gb);
  uint8_t	color = GET_PD_COLOR(pixel);

  color = get_pixel_color(gb, *(gb->hregisters.bgp + GET_PD_SOURCE(pixel)), color);
  draw_pixel(gb, gb->gpu.ppu.x, gb->gpu.ppu.y, color);
  gb->gpu.ppu.x = (gb->gpu.ppu.x + 1) % SCREEN_WIDTH;
}

static void	draw_line(t_gameboy *gb)
{
  unsigned	sprite = 0;

  gb->gpu.ppu.x = 0;
  gb->gpu.ppu.y = *gb->hregisters.ly;
  clear_fifo(gb);
  for (unsigned i = 0; i < SCREEN_WIDTH; ++i) {
      while (gb->gpu.pff.size <= 8) {
	  fetcher_step(gb);
	  push_fetch_to_fifo(gb);
      }

sprite_loop:
      if (sprite != gb->gpu.oam.index) {
	  t_oam_entry const *entry = (t_oam_entry const *)(gb->memory.start + gb->gpu.oam.array[sprite]);

	  if ((entry->pos_x - 8) == (int)gb->gpu.ppu.x) {
	      fetch_sprite(gb, entry);
	      ++sprite;
	      goto sprite_loop;
	  }
      }
      ppu_step(gb);
  }
}

static void     update_gpu(t_gameboy *gb)
{
  uint8_t     mode = *gb->hregisters.stat & 0x3;

  gb->gpu.mode_counter += gb->instruction.cycles;
  switch (mode)
    {
      // H-Blank
    case GM_HBLANK:
      if (gb->gpu.mode_counter >= 204)
	{
	  gb->gpu.mode_counter -= 204;
	  ++(*gb->hregisters.ly);

	  if (*gb->hregisters.ly == SCREEN_HEIGHT - 1) {
	      *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, GM_VBLANK);
	      refresh_screen(gb);
	      clear_screen(gb);
	      joypad_step(gb);
	      timing(gb);
	  }
	  else {
	      *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, GM_OAM_SEARCH);
	  }
	}
      break;
      // V-Blank
    case GM_VBLANK:
      if (gb->gpu.mode_counter >= 456)
	{
	  gb->gpu.mode_counter -= 456;
	  (*gb->hregisters.ly)++;
	  if ((*gb->hregisters.ly) == 153)
	    {
	      *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, GM_OAM_SEARCH);
	      (*gb->hregisters.ly) = 0;
	      ask_vblank_interrupt(gb->hregisters._if);
	    }
	}
      break;
      // OAM Search
    case GM_OAM_SEARCH:
      if (gb->gpu.mode_counter >= 80)
	{
	  oam_search(gb, *gb->hregisters.ly);
	  gb->gpu.mode_counter -= 80;
	  *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, GM_PIXEL_TRANSFER);
	}
      break;
      // Pixel transfer
    case GM_PIXEL_TRANSFER:
      if (gb->gpu.mode_counter >= 172)
	{
	  gb->gpu.mode_counter -= 172;
	  set_fetcher_address(gb, ((*gb->hregisters.ly / 8 * BG_MAP_HW)));
	  draw_line(gb);
	  *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, GM_HBLANK);
	}
      break;
    }
}

#warning "Implement half sprite on screen"

void		gpu_step(t_gameboy *gb)
{
  unsigned char	lcdc = *gb->hregisters.lcdc;

  update_gpu(gb);
  if (!(lcdc & LCDC_LCD_ENABLE))
    return ;
}
