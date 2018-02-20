#include <stdio.h>
#include "gameboy.h"
#include "debug.h"
#include "infos.h"
#include "instructions.h"
#include "memory_rw.h"

static void	get_operand(t_gameboy *gb, uint8_t instr_length)
{
  if (instr_length == 1)
    gb->instruction.op_len8 = fetch_byte(gb, gb->registers.pc + 1);
  else if (instr_length == 2)
    gb->instruction.op_len16 = fetch_word(gb, gb->registers.pc + 1);
}

void				cpu_step(t_gameboy *gb)
{
  gb->instruction.opcode = gb->memory.start[gb->registers.pc];
  gb->instruction.cycles = g_instructions[gb->instruction.opcode].nb_cycles;
  get_operand(gb, g_instructions[gb->instruction.opcode].instr_length);
  debug_step(gb);
  gb->registers.pc += g_instructions[gb->instruction.opcode].instr_length + 1;
  if (gb->instruction.cycles != 0) {
      (g_instructions[gb->instruction.opcode].func)(gb);
    }
  else {
      fprintf(stderr, "Unimplemented instruction %02X !\n", gb->instruction.opcode);
    }
}
