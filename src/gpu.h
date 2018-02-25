#ifndef GPU_H_
# define GPU_H_

# include <SDL/SDL.h>
# include <stdbool.h>

# define SCREEN_WIDTH 160
# define SCREEN_HEIGHT 144

# define BG_MAP_HW 32
# define DEFAULT_SCREEN_SCALING 4

# define PIXEL_FIFO_SIZE 16
# define FETCHED_PIXEL_SIZE 8

# define OAM_RAM_SIZE 40
# define OAM_ENTRY_SIZE 4
# define OAM_ARRAY_MAX 10


# define TILE_SIZE 16

# define UPPER_BOUND(x, bound) ((x) > (bound) ? (bound) : (x))

# define SET_STAT_MODE(value, mode) (((value) & (0xFF ^ 0x3)) | (mode))

# define LYC_COINCIDENCE_BIT (1 << 6)

enum e_gpu_mode {
    GM_HBLANK,
    GM_VBLANK,
    GM_OAM_SEARCH,
    GM_PIXEL_TRANSFER,
};

enum e_lcdc {
    LCDC_LCD_ENABLE = 1 << 7,
    LCDC_WTM_SELECT = 1 << 6,
    LCDC_W_ENABLE = 1 << 5,
    LCDC_BGWTD_SELECT = 1 << 4,
    LCDC_BGTM_SELECT = 1 << 3,
    LCDC_OBJ_SIZE = 1 << 2,
    LCDC_OBJ_ENABLE = 1 << 1,
    LCDC_BG_DISPLAY = 1 << 0
};

enum e_pixel_source {
    PS_BG = 0,
    PS_OBJ0 = 1,
    PS_OBJ1 = 2
};

# define PD_COLOR (0b11)
# define PD_SOURCE (0b1100)

# define SET_PD_COLOR(x, value) ((x) | ((value) & 0b11))
# define SET_PD_SOURCE(x, value) ((x) | (((value) & 0b11) << 2))

# define GET_PD_COLOR(x) ((x) & PD_COLOR)
# define GET_PD_SOURCE(x) (((x) & PD_SOURCE) >> 2)

# define GET_SPRITE_HEIGHT(x) (((x) & LCDC_OBJ_SIZE) ? 16 : 8)

# define GET_OAM_PALETTE(x) (((x) & 0b10000) >> 4)
# define GET_OAM_PRIORITY(x) (((x) & 0b10000000) >> 7)

/* Bit 0-1 : color; Bit 2-3: source */
typedef uint8_t t_pixel_data;

typedef struct  s_pixel_fetcher
{
  uint16_t      address;
  t_pixel_data  data[8];
}               t_pixel_fetcher;

typedef struct  s_pixel_fifo
{
  t_pixel_data  fifo[PIXEL_FIFO_SIZE];
  uint8_t       head;
  uint8_t       tail;
  uint8_t       size;
  uint8_t       on;
}               t_pixel_fifo;

typedef struct s_oam_entry
{
  uint8_t       pos_y;
  uint8_t       pos_x;
  uint8_t       tile;
  uint8_t       flags;
}               t_oam_entry;

typedef struct s_display
{
  uint8_t       palette[4];
  uint8_t       scale;
  unsigned      width;
  unsigned      height;
  SDL_Surface   *screen;
}               t_display;

typedef struct  s_oam
{
  uint16_t      array[OAM_ARRAY_MAX];
  uint8_t       index;
}               t_oam;

typedef struct s_ppu
{
  unsigned     x;
  unsigned     y;
}              t_ppu;

# define SET_INPUT_ROW(x, row) ((x) = (x) & ~(row))

typedef struct s_input
{
  SDLKey       value;
  uint8_t      row;
  uint8_t      button;
}              t_input;

typedef struct    s_gpu
{
  uint8_t         *pixels;
  t_display       display;
  unsigned        mode_counter;

  t_pixel_fifo    pff;
  t_pixel_fetcher fetcher;

  t_oam           oam;
  t_ppu           ppu;
}                 t_gpu;

typedef struct s_gameboy t_gameboy;

void init_gpu(t_gameboy *gb);
bool start_gpu(t_gameboy *gb);
void dump_vram(t_gameboy *gb);
void dump_background_tile_map(t_gameboy *gb);
void gpu_step(t_gameboy *gb);

#endif /* !GPU_H_ */
