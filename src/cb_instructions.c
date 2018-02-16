#include "gameboy.h"
#include "memory_rw.h"
#include "instructions.h"
#include "cb_instructions.h"

void	cb_instr_swap_a_a(t_gameboy *gb)
{
  gb->registers.a = SWAP_NIBLES(gb->registers.a);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_b(t_gameboy *gb)
{
  gb->registers.b = SWAP_NIBLES(gb->registers.b);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_c(t_gameboy *gb)
{
  gb->registers.c = SWAP_NIBLES(gb->registers.c);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_d(t_gameboy *gb)
{
  gb->registers.d = SWAP_NIBLES(gb->registers.d);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_e(t_gameboy *gb)
{
  gb->registers.e = SWAP_NIBLES(gb->registers.e);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_h(t_gameboy *gb)
{
  gb->registers.h = SWAP_NIBLES(gb->registers.h);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_l(t_gameboy *gb)
{
  gb->registers.l = SWAP_NIBLES(gb->registers.l);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_swap_a_hlp(t_gameboy *gb)
{
  unsigned char		value = fetch_byte(gb, gb->registers.hl);

  write_byte(gb, gb->registers.hl, SWAP_NIBLES(value));
  set_if_zero(&gb->registers, value);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void	cb_instr_rlc_a(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.a);

  gb->registers.a = (gb->registers.a << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_b(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.b);

  gb->registers.b = (gb->registers.b << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_c(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.c);

  gb->registers.c = (gb->registers.c << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_d(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.d);

  gb->registers.d = (gb->registers.d << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_e(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.e);

  gb->registers.e = (gb->registers.e << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_h(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.h);

  gb->registers.h = (gb->registers.h << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_l(t_gameboy *gb)
{
  bool			bit = IS_NEG(gb->registers.l);

  gb->registers.l = (gb->registers.l << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rlc_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			bit = IS_NEG(res);

  res = (res << 1) | bit;
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void	cb_instr_rl_a(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.a);

  gb->registers.a = (gb->registers.a << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_b(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.b);

  gb->registers.b = (gb->registers.b << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_c(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.c);

  gb->registers.c = (gb->registers.c << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_d(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.d);

  gb->registers.d = (gb->registers.d << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_e(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.e);

  gb->registers.e = (gb->registers.e << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_h(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.h);

  gb->registers.h = (gb->registers.h << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_l(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.l);

  gb->registers.l = (gb->registers.l << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rl_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			head = IS_NEG(res);

  res = (res << 1) | get_carry_flag(gb->registers.f);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_rrc_a(t_gameboy *gb)
{
  bool			tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_b(t_gameboy *gb)
{
  bool			tail = (gb->registers.b & 0x01);

  gb->registers.b = (gb->registers.b >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_c(t_gameboy *gb)
{
  bool			tail = (gb->registers.c & 0x01);

  gb->registers.c = (gb->registers.c >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_d(t_gameboy *gb)
{
  bool			tail = (gb->registers.c & 0x01);

  gb->registers.d = (gb->registers.d >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_e(t_gameboy *gb)
{
  bool			tail = (gb->registers.e & 0x01);

  gb->registers.e = (gb->registers.e >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_h(t_gameboy *gb)
{
  bool			tail = (gb->registers.h & 0x01);

  gb->registers.h = (gb->registers.h >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_l(t_gameboy *gb)
{
  bool			tail = (gb->registers.l & 0x01);

  gb->registers.l = (gb->registers.l >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rrc_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			tail = (res & 0x01);

  res = (res >> 1) | (tail << 7);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_a(t_gameboy *gb)
{
  bool			tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_b(t_gameboy *gb)
{
  bool			tail = (gb->registers.b & 0x01);

  gb->registers.b = (gb->registers.b >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_c(t_gameboy *gb)
{
  bool			tail = (gb->registers.a & 0x01);

  gb->registers.c = (gb->registers.c >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_d(t_gameboy *gb)
{
  bool			tail = (gb->registers.d & 0x01);

  gb->registers.d = (gb->registers.d >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_e(t_gameboy *gb)
{
  bool			tail = (gb->registers.e & 0x01);

  gb->registers.e = (gb->registers.e >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_h(t_gameboy *gb)
{
  bool			tail = (gb->registers.h & 0x01);

  gb->registers.h = (gb->registers.h >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_l(t_gameboy *gb)
{
  bool			tail = (gb->registers.l & 0x01);

  gb->registers.l = (gb->registers.l >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_rr_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			tail = (res & 0x01);

  res = (res >> 1) | (get_carry_flag(gb->registers.f) << 7);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sla_a(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.a);

  gb->registers.a = (gb->registers.a << 1);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_b(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.b);

  gb->registers.b = (gb->registers.b << 1);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_c(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.c);

  gb->registers.c = (gb->registers.c << 1);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_d(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.d);

  gb->registers.d = (gb->registers.d << 1);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_e(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.e);

  gb->registers.e = (gb->registers.e << 1);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_h(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.h);

  gb->registers.h = (gb->registers.h << 1);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_l(t_gameboy *gb)
{
  bool			head = IS_NEG(gb->registers.l);

  gb->registers.l = (gb->registers.l << 1);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sla_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			head = IS_NEG(res);

  res = (res << 1);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void	cb_instr_sra_a(t_gameboy *gb)
{
  bool			tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1) | (IS_NEG(gb->registers.a) << 7);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_b(t_gameboy *gb)
{
  bool			tail = (gb->registers.b & 0x01);

  gb->registers.b = (gb->registers.b >> 1) | (IS_NEG(gb->registers.b) << 7);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_c(t_gameboy *gb)
{
  bool			tail = (gb->registers.c & 0x01);

  gb->registers.c = (gb->registers.c >> 1) | (IS_NEG(gb->registers.c) << 7);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_d(t_gameboy *gb)
{
  bool			tail = (gb->registers.d & 0x01);

  gb->registers.d = (gb->registers.d >> 1) | (IS_NEG(gb->registers.d) << 7);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_e(t_gameboy *gb)
{
  bool			tail = (gb->registers.e & 0x01);

  gb->registers.e = (gb->registers.e >> 1) | (IS_NEG(gb->registers.e) << 7);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_h(t_gameboy *gb)
{
  bool			tail = (gb->registers.h & 0x01);

  gb->registers.h = (gb->registers.h >> 1) | (IS_NEG(gb->registers.h) << 7);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_l(t_gameboy *gb)
{
  bool			tail = (gb->registers.l & 0x01);

  gb->registers.l = (gb->registers.l >> 1) | (IS_NEG(gb->registers.l) << 7);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_sra_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			tail = (res & 0x01);

  res = (res >> 1) | (IS_NEG(res) << 7);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_a(t_gameboy *gb)
{
  bool			tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_b(t_gameboy *gb)
{
  bool			tail = (gb->registers.b & 0x01);

  gb->registers.b = (gb->registers.b >> 1);
  set_if_zero(&gb->registers, gb->registers.b);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_c(t_gameboy *gb)
{
  bool			tail = (gb->registers.c & 0x01);

  gb->registers.c = (gb->registers.c >> 1);
  set_if_zero(&gb->registers, gb->registers.c);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_d(t_gameboy *gb)
{
  bool			tail = (gb->registers.d & 0x01);

  gb->registers.d = (gb->registers.d >> 1);
  set_if_zero(&gb->registers, gb->registers.d);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_e(t_gameboy *gb)
{
  bool			tail = (gb->registers.e & 0x01);

  gb->registers.e = (gb->registers.e >> 1);
  set_if_zero(&gb->registers, gb->registers.e);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_h(t_gameboy *gb)
{
  bool			tail = (gb->registers.h & 0x01);

  gb->registers.h = (gb->registers.h >> 1);
  set_if_zero(&gb->registers, gb->registers.h);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_l(t_gameboy *gb)
{
  bool			tail = (gb->registers.l & 0x01);

  gb->registers.l = (gb->registers.l >> 1);
  set_if_zero(&gb->registers, gb->registers.l);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_srl_hlp(t_gameboy *gb)
{
  unsigned char		res = fetch_byte(gb, gb->registers.hl);
  bool			tail = (res & 0x01);

  res = (res >> 1);
  write_byte(gb, gb->registers.hl, res);
  set_if_zero(&gb->registers, res);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void	cb_instr_bit_0_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_0_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 0));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_1_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 1));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_2_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 2));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_3_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 3));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_4_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 4));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_5_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 5));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_6_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 6));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_a(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.a & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_b(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.b & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_c(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.c & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_d(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.d & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_e(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.e & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_h(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.h & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_l(t_gameboy *gb)
{
  set_if_zero(&gb->registers, gb->registers.l & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_bit_7_hlp(t_gameboy *gb)
{
  set_if_zero(&gb->registers, fetch_byte(gb, gb->registers.hl) & (1 << 7));
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void	cb_instr_set_0_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 0);
}

void	cb_instr_set_0_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 0);
}

void	cb_instr_set_0_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 0);
}

void	cb_instr_set_0_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 0);
}

void	cb_instr_set_0_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 0);
}

void	cb_instr_set_0_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 0);
}

void	cb_instr_set_0_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 0);
}

void	cb_instr_set_0_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 0);
}

void	cb_instr_set_1_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 1);
}

void	cb_instr_set_1_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 1);
}

void	cb_instr_set_1_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 1);
}

void	cb_instr_set_1_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 1);
}

void	cb_instr_set_1_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 1);
}

void	cb_instr_set_1_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 1);
}

void	cb_instr_set_1_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 1);
}

void	cb_instr_set_1_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 1);
}

void	cb_instr_set_2_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 2);
}

void	cb_instr_set_2_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 2);
}

void	cb_instr_set_2_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 2);
}

void	cb_instr_set_2_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 2);
}

void	cb_instr_set_2_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 2);
}

void	cb_instr_set_2_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 2);
}

void	cb_instr_set_2_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 2);
}

void	cb_instr_set_2_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 2);
}

void	cb_instr_set_3_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 3);
}

void	cb_instr_set_3_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 3);
}

void	cb_instr_set_3_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 3);
}

void	cb_instr_set_3_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 3);
}

void	cb_instr_set_3_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 3);
}

void	cb_instr_set_3_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 3);
}

void	cb_instr_set_3_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 3);
}

void	cb_instr_set_3_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 3);
}

void	cb_instr_set_4_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 4);
}

void	cb_instr_set_4_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 4);
}

void	cb_instr_set_4_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 4);
}

void	cb_instr_set_4_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 4);
}

void	cb_instr_set_4_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 4);
}

void	cb_instr_set_4_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 4);
}

void	cb_instr_set_4_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 4);
}

void	cb_instr_set_4_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 4);
}

void	cb_instr_set_5_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 5);
}

void	cb_instr_set_5_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 5);
}

void	cb_instr_set_5_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 5);
}

void	cb_instr_set_5_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 5);
}

void	cb_instr_set_5_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 5);
}

void	cb_instr_set_5_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 5);
}

void	cb_instr_set_5_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 5);
}

void	cb_instr_set_5_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 5);
}

void	cb_instr_set_6_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 6);
}

void	cb_instr_set_6_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 6);
}

void	cb_instr_set_6_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 6);
}

void	cb_instr_set_6_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 6);
}

void	cb_instr_set_6_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 6);
}

void	cb_instr_set_6_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 6);
}

void	cb_instr_set_6_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 6);
}

void	cb_instr_set_6_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 6);
}

void	cb_instr_set_7_a(t_gameboy *gb)
{
  gb->registers.a |= (1 << 7);
}

void	cb_instr_set_7_b(t_gameboy *gb)
{
  gb->registers.b |= (1 << 7);
}

void	cb_instr_set_7_c(t_gameboy *gb)
{
  gb->registers.c |= (1 << 7);
}

void	cb_instr_set_7_d(t_gameboy *gb)
{
  gb->registers.d |= (1 << 7);
}

void	cb_instr_set_7_e(t_gameboy *gb)
{
  gb->registers.e |= (1 << 7);
}

void	cb_instr_set_7_h(t_gameboy *gb)
{
  gb->registers.h |= (1 << 7);
}

void	cb_instr_set_7_l(t_gameboy *gb)
{
  gb->registers.l |= (1 << 7);
}

void	cb_instr_set_7_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] |= (1 << 7);
}

void	cb_instr_res_0_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 0);
}

void	cb_instr_res_0_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 0);
}

void	cb_instr_res_0_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 0);
}

void	cb_instr_res_0_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 0);
}

void	cb_instr_res_0_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 0);
}

void	cb_instr_res_0_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 0);
}

void	cb_instr_res_0_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 0);
}

void	cb_instr_res_0_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 0);
}

void	cb_instr_res_1_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 1);
}

void	cb_instr_res_1_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 1);
}

void	cb_instr_res_1_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 1);
}

void	cb_instr_res_1_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 1);
}

void	cb_instr_res_1_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 1);
}

void	cb_instr_res_1_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 1);
}

void	cb_instr_res_1_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 1);
}

void	cb_instr_res_1_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 1);
}

void	cb_instr_res_2_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 2);
}

void	cb_instr_res_2_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 2);
}

void	cb_instr_res_2_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 2);
}

void	cb_instr_res_2_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 2);
}

void	cb_instr_res_2_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 2);
}

void	cb_instr_res_2_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 2);
}

void	cb_instr_res_2_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 2);
}

void	cb_instr_res_2_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 2);
}

void	cb_instr_res_3_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 3);
}

void	cb_instr_res_3_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 3);
}

void	cb_instr_res_3_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 3);
}

void	cb_instr_res_3_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 3);
}

void	cb_instr_res_3_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 3);
}

void	cb_instr_res_3_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 3);
}

void	cb_instr_res_3_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 3);
}

void	cb_instr_res_3_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 3);
}

void	cb_instr_res_4_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 4);
}

void	cb_instr_res_4_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 4);
}

void	cb_instr_res_4_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 4);
}

void	cb_instr_res_4_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 4);
}

void	cb_instr_res_4_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 4);
}

void	cb_instr_res_4_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 4);
}

void	cb_instr_res_4_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 4);
}

void	cb_instr_res_4_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 4);
}

void	cb_instr_res_5_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 5);
}

void	cb_instr_res_5_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 5);
}

void	cb_instr_res_5_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 5);
}

void	cb_instr_res_5_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 5);
}

void	cb_instr_res_5_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 5);
}

void	cb_instr_res_5_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 5);
}

void	cb_instr_res_5_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 5);
}

void	cb_instr_res_5_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 5);
}

void	cb_instr_res_6_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 6);
}

void	cb_instr_res_6_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 6);
}

void	cb_instr_res_6_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 6);
}

void	cb_instr_res_6_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 6);
}

void	cb_instr_res_6_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 6);
}

void	cb_instr_res_6_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 6);
}

void	cb_instr_res_6_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 6);
}

void	cb_instr_res_6_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 6);
}

void	cb_instr_res_7_a(t_gameboy *gb)
{
  gb->registers.a &= ~(1 << 7);
}

void	cb_instr_res_7_b(t_gameboy *gb)
{
  gb->registers.b &= ~(1 << 7);
}

void	cb_instr_res_7_c(t_gameboy *gb)
{
  gb->registers.c &= ~(1 << 7);
}

void	cb_instr_res_7_d(t_gameboy *gb)
{
  gb->registers.d &= ~(1 << 7);
}

void	cb_instr_res_7_e(t_gameboy *gb)
{
  gb->registers.e &= ~(1 << 7);
}

void	cb_instr_res_7_h(t_gameboy *gb)
{
  gb->registers.h &= ~(1 << 7);
}

void	cb_instr_res_7_l(t_gameboy *gb)
{
  gb->registers.l &= ~(1 << 7);
}

void	cb_instr_res_7_hlp(t_gameboy *gb)
{
  gb->memory.start[gb->registers.hl] &= ~(1 << 7);
}
