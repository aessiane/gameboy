#include <string.h>
#include <stdlib.h>
#include "gameboy.h"
#include "errors.h"

static void	init_cartbridge(t_gameboy *gb)
{
  gb->memory.cb.rst_iv = gb->memory.start + RST_IV_INDEX;
  gb->memory.cb.header = gb->memory.start + HEADER_INDEX;
  gb->memory.cb.rom_bank_0 = gb->memory.start + ROM_BANK_0_INDEX;
  gb->memory.cb.rom_banks = gb->memory.start + ROM_BANKS_INDEX;

  memcpy(gb->memory.start, gb->rom.start, 0x8000);
}

static void	init_vram(uint8_t *start, t_vram *vram)
{
  vram->character_ram = start + CHARACTER_RAM_INDEX;
  vram->bg_map_1 = start + BG_MAP_1_INDEX;
  vram->bg_map_2 = start + BG_MAP_2_INDEX;
}

static void	init_ram(uint8_t *start, t_ram *ram)
{
  ram->cb = start + CARTBRIDGE_RAM_INDEX;
  ram->internal = start + INTERNAL_RAM_INDEX;
  ram->echo = start + ECHO_RAM_INDEX;
  ram->oam = start + OAM_INDEX;
  ram->high = start + HIGH_RAM_INDEX;
}

int		init_memory(t_gameboy *gb)
{
  if ((gb->memory.start = malloc(MEMORY_SIZE)) == NULL)
    return (perr(FUNC_ERR("malloc")));
  memset(gb->memory.start, 0, MEMORY_SIZE);
  init_cartbridge(gb);
  init_vram(gb->memory.start, &gb->memory.vram);
  init_ram(gb->memory.start, &gb->memory.ram);
  gb->memory.io = (uint8_t *)IO_REGISTERS_INDEX;
  gb->memory.interupt = (uint8_t *)INTERRUPT_ENABLE_INDEX;
  return (0);
}
