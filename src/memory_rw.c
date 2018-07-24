#include <stdio.h>
#include "memory.h"
#include "gameboy.h"

uint8_t fetch_byte(t_gameboy *gb, uint16_t address)
{
  if (address == 0xFF00) {
      return (get_keys_value(*gb->hregisters.p1, gb->joypad.keys));
  }
  return (gb->memory.start[address]);
}

uint16_t fetch_word(t_gameboy *gb, uint16_t address)
{
  return ((fetch_byte(gb, address) & 0x00FF) |
          (fetch_byte(gb, address + 1) << 8));
}

void        write_byte(t_gameboy *gb, uint16_t address, uint8_t value)
{
  uint16_t  offset;

  gb->memory.start[address] = value;
  if (address >= INTERNAL_RAM_INDEX && address < OAM_INDEX) {
      offset = address -
        (address > ECHO_RAM_INDEX ? ECHO_RAM_INDEX : INTERNAL_RAM_INDEX);
      if (offset < OAM_INDEX - ECHO_RAM_INDEX)
        gb->memory.ram.echo[offset] = value;
  }
  else {
      // Hardware interruptions
      switch (address) {
          // DIV
        case 0xFF04:
            gb->memory.start[0xFF04] = 0;
            break;
            // LY
        case 0xFF44:
            gb->memory.start[0xFF44] = 0;
            break;
            // DMA
        case 0xFF46:
              {
                uint16_t dest = gb->memory.start[address] << 8 ;

                for (unsigned i = 0 ; i < 0xA0; i++)
                  {
                    write_byte(gb, 0xFE00 + i, fetch_byte(gb, dest + i)) ;
                  }
              }
#warning "Implement DMA well"
            break;
        case 0xFFFF:
            break;
        case 0xFF80:
            break;
        default:
            break;
      };
  }
}

void write_word(t_gameboy *gb, uint16_t address, uint16_t value)
{
  write_byte(gb, address, (uint8_t)(value & 0x00FF));
  write_byte(gb, address + 1, (uint8_t)((value & 0xFF00) >> 8));
}

uint8_t pop_byte(t_gameboy *gb)
{
  return (gb->memory.start[gb->registers.sp++]);
}

uint16_t pop_word(t_gameboy *gb)
{
  return ((pop_byte(gb) & 0x00FF) | (pop_byte(gb) << 8));
}

void push_byte(t_gameboy *gb, uint8_t value)
{
  gb->memory.start[--gb->registers.sp] = value;
}

void push_word(t_gameboy *gb, uint16_t value)
{
  push_byte(gb, (value & 0xFF00) >> 8);
  push_byte(gb, value & 0x00FF);
}
