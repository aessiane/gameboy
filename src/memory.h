#ifndef MEMORY_H_
# define MEMORY_H_

# include <stdint.h>
# define MEMORY_SIZE	0x10000
# define L_ENDIAN

typedef struct s_gameboy	t_gameboy;

enum			e_memory_map_indexes {
    CARTBRIDGE_INDEX		= 0x0000,
    RST_IV_INDEX		= CARTBRIDGE_INDEX,
    HEADER_INDEX		= 0x0100,
    ROM_BANK_0_INDEX		= 0x0150,
    ROM_BANKS_INDEX		= 0x4000,
    VRAM_INDEX			= 0x8000,
    CHARACTER_RAM_INDEX		= VRAM_INDEX,
    BG_MAP_1_INDEX		= 0x9800,
    BG_MAP_2_INDEX		= 0x9C00,
    RAM_INDEX			= 0xA000,
    CARTBRIDGE_RAM_INDEX	= RAM_INDEX,
    INTERNAL_RAM_INDEX		= 0xC000,
    ECHO_RAM_INDEX		= 0xE000,
    OAM_INDEX			= 0xFE00,
    IO_REGISTERS_INDEX		= 0xFF00,
    HIGH_RAM_INDEX		= 0xFF80,
    INTERRUPT_ENABLE_INDEX	= 0xFFFF

};

typedef struct		s_cartbridge
{
  uint8_t		*rst_iv;
  uint8_t		*header;
  uint8_t		*rom_bank_0;
  uint8_t		*rom_banks;
}			t_cartbridge;

typedef struct		s_vram
{
  uint8_t		*character_ram;
  uint8_t		*bg_map_1;
  uint8_t		*bg_map_2;
}			t_vram;

typedef struct		s_ram
{
  uint8_t		*cb;
  uint8_t		*internal;
  uint8_t		*echo;
  uint8_t		*oam;
  uint8_t		*high;
}			t_ram;

typedef struct		s_memory
{
  uint8_t		*start;
  t_cartbridge		cb;
  t_vram		vram;
  t_ram			ram;
  uint8_t		*io;
  uint8_t		*interupt;
}			t_memory;

int			init_memory(t_gameboy *gb);

#endif /* !MEMORY_H_ */
