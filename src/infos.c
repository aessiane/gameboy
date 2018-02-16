#include <string.h>
#include <stdio.h>
#include "gameboy.h"
#include "rom.h"
#include "instructions.h"
#include "infos.h"

static void	print_cartbridge_type(unsigned char ct)
{
  for (unsigned i = 0; i < (sizeof(g_cb_types) / sizeof(g_cb_types[0])); ++i)
    {
      if (g_cb_types[i].key == ct)
	{
	  printf("Cartbridge type: %s\n", g_cb_types[i].value);
	  return ; }
    }
}

static void	print_rom_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_rom_sizes) / sizeof(g_rom_sizes)); ++i)
    {
      if (g_rom_sizes[i].key == rs)
	{
	  printf("Rom size: %s\n", g_rom_sizes[i].value);
	  return ;
	}
    }
}

static void	print_ram_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_ram_sizes) / sizeof(g_ram_sizes)); ++i)
    {
      if (g_ram_sizes[i].key == rs)
	{
	  printf("Ram size: %s\n", g_ram_sizes[i].value);
	  return ;
	}
    }
}

void		print_header_infos(t_header *header)
{
  char		title[17];

  strncpy(title, header->title, sizeof(header->title));
  title[16] = 0;
  printf("Title of the game: %s\n", title);
  print_cartbridge_type(header->cart_type);
  print_rom_size(header->cart_rom_size);
  print_ram_size(header->cart_ram_size);
  printf("_________________________\n\n");
}

void		print_instruction_infos(t_gameboy *gb, unsigned char opcode)
{
  printf("%02hhX", opcode);

  if (g_instructions[opcode].instr_length == 0)
    {
      printf("    : ");
      printf("%s", g_instructions[opcode].debug);
    }
  else if (g_instructions[opcode].instr_length == 1)
    {
      printf("%02hhX  :", gb->instruction.op_len8);
      printf(g_instructions[opcode].debug, gb->instruction.op_len8);
    }
  else
    {
      printf("%02hhX%02hhX: ", (char)(gb->instruction.op_len16 & 0x00FF),
	     (char)((gb->instruction.op_len16 & 0xFF00) >> 8));
      printf(g_instructions[opcode].debug, gb->instruction.op_len16);
    }
  printf("\n_________________________\n\n");
}

static void	print_flags(t_gameboy *gb)
{
  char		flags[] = "[ZSHC]\n";

  if (!get_zero_flag(gb->registers.f))
    flags[1] = '-';
  if (!get_substract_flag(gb->registers.f))
    flags[2] = '-';
  if (!get_half_carry_flag(gb->registers.f))
    flags[3] = '-';
  if (!get_carry_flag(gb->registers.f))
    flags[4] = '-';
  printf("%s", flags);
}

void		print_registers(t_gameboy *gb)
{
  printf("A: 0x%02hhX F: 0x%02hhX (AF: 0x%04hX)\n",
	 gb->registers.a, gb->registers.f, gb->registers.af);
  printf("B: 0x%02hhX C: 0x%02hhX (BC: 0x%04hX)\n",
	 gb->registers.b, gb->registers.c, gb->registers.bc);
  printf("D: 0x%02hhX E: 0x%02hhX (DE: 0x%04hX)\n",
	 gb->registers.d, gb->registers.e, gb->registers.de);
  printf("H: 0x%02hhX L: 0x%02hhX (HL: 0x%04hX)\n",
	 gb->registers.h, gb->registers.l, gb->registers.hl);
  printf("SP: 0x%04hX\n", gb->registers.sp);
  printf("PC: 0x%04hX\n", gb->registers.pc);
  print_flags(gb);
  printf("_________________________\n\n");
}
