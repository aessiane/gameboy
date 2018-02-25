#include "memory_rw.h"
#include "instructions.h"
#include "cb_instructions.h"
#include "gameboy.h"

/*
**                              8-BIT LOADS
** _________________________________________________________________________
*/

// lD nn, d8 : put value nn into d8.
void    instr_ld_b_d8(t_gameboy *gb)
{
  gb->registers.b = gb->instruction.op_len8;
}

void    instr_ld_c_d8(t_gameboy *gb)
{
  gb->registers.c = gb->instruction.op_len8;
}

void    instr_ld_d_d8(t_gameboy *gb)
{
  gb->registers.d = gb->instruction.op_len8;
}

void    instr_ld_e_d8(t_gameboy *gb)
{
  gb->registers.e = gb->instruction.op_len8;
}

void    instr_ld_h_d8(t_gameboy *gb)
{
  gb->registers.h = gb->instruction.op_len8;
}

void    instr_ld_l_d8(t_gameboy *gb)
{
  gb->registers.l = gb->instruction.op_len8;
}

// LD r1, r2 : put value r2 into r1.
void    instr_ld_a_a(t_gameboy *gb)
{
  gb->registers.a = gb->registers.a;
}

void    instr_ld_a_b(t_gameboy *gb)
{
  gb->registers.a = gb->registers.b;
}

void    instr_ld_a_c(t_gameboy *gb)
{
  gb->registers.a = gb->registers.c;
}

void    instr_ld_a_d(t_gameboy *gb)
{
  gb->registers.a = gb->registers.d;
}

void    instr_ld_a_e(t_gameboy *gb)
{
  gb->registers.a = gb->registers.e;
}

void    instr_ld_a_h(t_gameboy *gb)
{
  gb->registers.a = gb->registers.h;
}

void    instr_ld_a_l(t_gameboy *gb)
{
  gb->registers.a = gb->registers.l;
}

void    instr_ld_a_hl(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_b_b(t_gameboy *gb)
{
  gb->registers.b = gb->registers.b;
}

void    instr_ld_b_c(t_gameboy *gb)
{
  gb->registers.b = gb->registers.c;
}

void    instr_ld_b_d(t_gameboy *gb)
{
  gb->registers.b = gb->registers.d;
}

void    instr_ld_b_e(t_gameboy *gb)
{
  gb->registers.b = gb->registers.e;
}

void    instr_ld_b_h(t_gameboy *gb)
{
  gb->registers.b = gb->registers.h;
}

void    instr_ld_b_l(t_gameboy *gb)
{
  gb->registers.b = gb->registers.l;
}

void    instr_ld_b_hl(t_gameboy *gb)
{
  gb->registers.b = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_c_b(t_gameboy *gb)
{
  gb->registers.c = gb->registers.b;
}

void    instr_ld_c_c(t_gameboy *gb)
{
  gb->registers.c = gb->registers.c;
}

void    instr_ld_c_d(t_gameboy *gb)
{
  gb->registers.c = gb->registers.d;
}

void    instr_ld_c_e(t_gameboy *gb)
{
  gb->registers.c = gb->registers.e;
}

void    instr_ld_c_h(t_gameboy *gb)
{
  gb->registers.c = gb->registers.h;
}

void    instr_ld_c_l(t_gameboy *gb)
{
  gb->registers.c = gb->registers.l;
}

void    instr_ld_c_hl(t_gameboy *gb)
{
  gb->registers.c = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_d_b(t_gameboy *gb)
{
  gb->registers.d = gb->registers.b;
}

void    instr_ld_d_c(t_gameboy *gb)
{
  gb->registers.d = gb->registers.c;
}

void    instr_ld_d_d(t_gameboy *gb)
{
  gb->registers.d = gb->registers.d;
}

void    instr_ld_d_e(t_gameboy *gb)
{
  gb->registers.d = gb->registers.e;
}

void    instr_ld_d_h(t_gameboy *gb)
{
  gb->registers.d = gb->registers.h;
}

void    instr_ld_d_l(t_gameboy *gb)
{
  gb->registers.d = gb->registers.l;
}

void    instr_ld_d_hl(t_gameboy *gb)
{
  gb->registers.d = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_e_b(t_gameboy *gb)
{
  gb->registers.e = gb->registers.b;
}

void    instr_ld_e_c(t_gameboy *gb)
{
  gb->registers.e = gb->registers.c;
}

void    instr_ld_e_d(t_gameboy *gb)
{
  gb->registers.e = gb->registers.d;
}

void    instr_ld_e_e(t_gameboy *gb)
{
  gb->registers.e = gb->registers.e;
}

void    instr_ld_e_h(t_gameboy *gb)
{
  gb->registers.e = gb->registers.h;
}

void    instr_ld_e_l(t_gameboy *gb)
{
  gb->registers.e = gb->registers.l;
}

void    instr_ld_e_hl(t_gameboy *gb)
{
  gb->registers.e = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_h_b(t_gameboy *gb)
{
  gb->registers.h = gb->registers.b;
}

void    instr_ld_h_c(t_gameboy *gb)
{
  gb->registers.h = gb->registers.c;
}

void    instr_ld_h_d(t_gameboy *gb)
{
  gb->registers.h = gb->registers.d;
}

void    instr_ld_h_e(t_gameboy *gb)
{
  gb->registers.h = gb->registers.e;
}

void    instr_ld_h_h(t_gameboy *gb)
{
  gb->registers.h = gb->registers.h;
}

void    instr_ld_h_l(t_gameboy *gb)
{
  gb->registers.h = gb->registers.l;
}

void    instr_ld_h_hl(t_gameboy *gb)
{
  gb->registers.h = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_l_b(t_gameboy *gb)
{
  gb->registers.l = gb->registers.b;
}

void    instr_ld_l_c(t_gameboy *gb)
{
  gb->registers.l = gb->registers.c;
}

void    instr_ld_l_d(t_gameboy *gb)
{
  gb->registers.l = gb->registers.d;
}

void    instr_ld_l_e(t_gameboy *gb)
{
  gb->registers.l = gb->registers.e;
}

void    instr_ld_l_h(t_gameboy *gb)
{
  gb->registers.l = gb->registers.h;
}

void    instr_ld_l_l(t_gameboy *gb)
{
  gb->registers.l = gb->registers.l;
}

void    instr_ld_l_hl(t_gameboy *gb)
{
  gb->registers.l = fetch_byte(gb, gb->registers.hl);
}

void    instr_ld_hl_b(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.b);
}

void    instr_ld_hl_c(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.c);
}

void    instr_ld_hl_d(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.d);
}

void    instr_ld_hl_e(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.e);
}

void    instr_ld_hl_h(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.h);
}

void    instr_ld_hl_l(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.l);
}

void    instr_ld_hl_d8(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->instruction.op_len8);
}

void    instr_ld_a_bcp(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->registers.bc);
}

void    instr_ld_a_dep(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->registers.de);
}

void    instr_ld_a_a16(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->instruction.op_len16);
}

void    instr_ld_a_d8(t_gameboy *gb)
{
  gb->registers.a = gb->instruction.op_len8;
}

void    instr_ld_b_a(t_gameboy *gb)
{
  gb->registers.b = gb->registers.a;
}

void    instr_ld_c_a(t_gameboy *gb)
{
  gb->registers.c = gb->registers.a;
}

void    instr_ld_d_a(t_gameboy *gb)
{
  gb->registers.d = gb->registers.a;
}

void    instr_ld_e_a(t_gameboy *gb)
{
  gb->registers.e = gb->registers.a;
}

void    instr_ld_h_a(t_gameboy *gb)
{
  gb->registers.h = gb->registers.a;
}

void    instr_ld_l_a(t_gameboy *gb)
{
  gb->registers.l = gb->registers.a;
}

void    instr_ld_bcp_a(t_gameboy *gb)
{
  write_byte(gb, gb->registers.bc, gb->registers.a);
}

void    instr_ld_dep_a(t_gameboy *gb)
{
  write_byte(gb, gb->registers.de, gb->registers.a);
}

void    instr_ld_hlp_a(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.a);
}

void    instr_ld_a16_a(t_gameboy *gb)
{
  write_byte(gb, gb->instruction.op_len16, gb->registers.a);
}

void    instr_ld_a_cp_ff00(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, (0xFF00 + (uint16_t)(gb->registers.c & 0xFF)));
}

void    instr_ld_cp_a_ff00(t_gameboy *gb)
{
   write_byte(gb, (0xFF00 + (uint16_t)(gb->registers.c & 0xFF)), gb->registers.a);
}

void    instr_ldd_a_hlp(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->registers.hl);
  --gb->registers.hl;
}

void    instr_ldd_hlp_a(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.a);
  --gb->registers.hl;
}

void    instr_ldi_a_hlp(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, gb->registers.hl);
  ++gb->registers.hl;
}

void    instr_ldi_hlp_a(t_gameboy *gb)
{
  write_byte(gb, gb->registers.hl, gb->registers.a);
  ++gb->registers.hl;
}

void    instr_ldh_d8_a(t_gameboy *gb)
{
  write_byte(gb, (0xFF00 + (uint16_t)(gb->instruction.op_len8 & 0xFF)), gb->registers.a);
}

void    instr_ldh_a_d8(t_gameboy *gb)
{
  gb->registers.a = fetch_byte(gb, (0xFF00 + (uint16_t)(gb->instruction.op_len8 & 0xFF)));
}

void    instr_ld_bc_d16(t_gameboy *gb)
{
  gb->registers.bc = gb->instruction.op_len16;
}

void    instr_ld_de_d16(t_gameboy *gb)
{
  gb->registers.de = gb->instruction.op_len16;
}

void    instr_ld_hl_d16(t_gameboy *gb)
{
  gb->registers.hl = gb->instruction.op_len16;
}

void    instr_ld_sp_d16(t_gameboy *gb)
{
  gb->registers.sp = gb->instruction.op_len16;
}

void    instr_ld_sp_hl(t_gameboy *gb)
{
  gb->registers.sp = gb->registers.hl;
}

void    instr_ldhl_sp_d8(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.sp;
  uint8_t         ro = fetch_byte(gb, gb->registers.sp);

  gb->registers.hl = lo + ro;
  unset_zero_flag(&gb->registers);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.hl);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_ld_d16_sp(t_gameboy *gb)
{
  write_word(gb, gb->instruction.op_len16, gb->registers.sp);
}

void    instr_push_af(t_gameboy *gb)
{
  push_word(gb, gb->registers.af);
}

void    instr_push_bc(t_gameboy *gb)
{
  push_word(gb, gb->registers.bc);
}

void    instr_push_de(t_gameboy *gb)
{
  push_word(gb, gb->registers.de);
}

void    instr_push_hl(t_gameboy *gb)
{
  push_word(gb, gb->registers.hl);
}

void    instr_pop_af(t_gameboy *gb)
{
  gb->registers.af = pop_word(gb);
}

void    instr_pop_bc(t_gameboy *gb)
{
  gb->registers.bc = pop_word(gb);
}

void    instr_pop_de(t_gameboy *gb)
{
  gb->registers.de = pop_word(gb);
}

void    instr_pop_hl(t_gameboy *gb)
{
  gb->registers.hl = pop_word(gb);
}

void    instr_add_a_a(t_gameboy *gb)
{
  uint8_t         uo = gb->registers.a;

  gb->registers.a += gb->registers.a;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, uo, uo, gb->registers.a);
  set_if_half_carry(&gb->registers, uo, uo);
}

void    instr_add_a_b(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.b;

  gb->registers.a += gb->registers.b;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_c(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.c;

  gb->registers.a += gb->registers.c;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_d(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.d;

  gb->registers.a += gb->registers.d;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_e(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.e;

  gb->registers.a += gb->registers.e;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_h(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.h;

  gb->registers.a += gb->registers.h;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_l(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.l;

  gb->registers.a += gb->registers.l;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_hlp(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = fetch_byte(gb, gb->registers.hl);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_add_a_d8(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->instruction.op_len8;

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_a(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.a + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_b(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.b + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_c(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.c + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_d(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.d + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_e(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.e + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_h(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.h + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_l(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.l + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_hlp(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = fetch_byte(gb, gb->registers.hl) + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_adc_a_d8(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->instruction.op_len8 + get_carry_flag(gb->registers.f);

  gb->registers.a += ro;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_if_carry(&gb->registers, lo, ro, gb->registers.a);
  set_if_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_a(t_gameboy *gb)
{
  uint8_t uo = gb->registers.a;

  gb->registers.a -= gb->registers.a;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, uo, uo);
  set_if_no_borrow_half_carry(&gb->registers, uo, uo);
}

void    instr_sub_a_b(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.b;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_c(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.c;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_d(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.d;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_e(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.e;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_h(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.h;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_l(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.l;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_hlp(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = fetch_byte(gb, gb->registers.hl);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sub_a_d8(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->instruction.op_len8;

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_a(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.a + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_b(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.b + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_c(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.c + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_d(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.d + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_e(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.e + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_h(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.h + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_l(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->registers.l + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_hlp(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = fetch_byte(gb, gb->registers.hl) + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_sbc_a_d8(t_gameboy *gb)
{
  uint8_t lo = gb->registers.a;
  uint8_t ro = gb->instruction.op_len8 + get_carry_flag(gb->registers.f);

  gb->registers.a -= ro;
  set_if_zero(&gb->registers, gb->registers.a);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_carry(&gb->registers, lo, ro);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
}

void    instr_and_a_a(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.a;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_b(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.b;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_c(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.c;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_d(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.d;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_e(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.e;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_h(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.h;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_l(t_gameboy *gb)
{
  gb->registers.a &= gb->registers.l;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_hlp(t_gameboy *gb)
{
  gb->registers.a &= fetch_byte(gb, gb->registers.hl);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_and_a_d8(t_gameboy *gb)
{
  gb->registers.a &= gb->instruction.op_len8;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_a(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.a;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_b(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.b;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_c(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.c;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_d(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.d;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_e(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.e;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_h(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.h;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_l(t_gameboy *gb)
{
  gb->registers.a |= gb->registers.l;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_hlp(t_gameboy *gb)
{
  gb->registers.a |= fetch_byte(gb, gb->registers.hl);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_or_a_d8(t_gameboy *gb)
{
  gb->registers.a |= gb->instruction.op_len8;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_a(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.a;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_b(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.b;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_c(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.c;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_d(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.d;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_e(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.e;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_h(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.h;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_l(t_gameboy *gb)
{
  gb->registers.a ^= gb->registers.l;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_hlp(t_gameboy *gb)
{
  gb->registers.a |= fetch_byte(gb, gb->registers.hl);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_xor_a_d8(t_gameboy *gb)
{
  gb->registers.a |= gb->instruction.op_len8;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  unset_carry_flag(&gb->registers);
}

void    instr_cp_a_a(t_gameboy *gb)
{
  set_zero_flag(&gb->registers);
  set_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void    instr_cp_a_b(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.b;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_c(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.c;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_d(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.d;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_e(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.e;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_h(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.h;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_l(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->registers.l;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_hlp(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = fetch_byte(gb, gb->registers.hl);

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_cp_a_d8(t_gameboy *gb)
{
  uint8_t         lo = gb->registers.a;
  uint8_t         ro = gb->instruction.op_len8;

  set_if_zero(&gb->registers, lo - ro);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, lo, ro);
  if (lo < ro)
    set_carry_flag(&gb->registers);
  else
    unset_carry_flag(&gb->registers);
}

void    instr_inc_a_a(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.a;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_b(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.b;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_c(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.c;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_d(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.d;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_e(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.e;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_h(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.h;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_l(t_gameboy *gb)
{
  uint8_t const           inc = ++gb->registers.l;

  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_inc_a_hlp(t_gameboy *gb)
{
  uint8_t         inc = fetch_byte(gb, gb->registers.hl);

  write_byte(gb, gb->registers.hl, ++inc);
  set_if_zero(&gb->registers, inc);
  unset_substract_flag(&gb->registers);
  set_if_half_carry(&gb->registers, inc - 1, 1);
}

void    instr_dec_a_a(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.a;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_b(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.b;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_c(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.c;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_d(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.d;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_e(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.e;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_h(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.h;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_l(t_gameboy *gb)
{
  uint8_t const   dec = --gb->registers.l;

  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_dec_a_hlp(t_gameboy *gb)
{
  uint8_t         dec = fetch_byte(gb, gb->registers.hl);

  write_byte(gb, gb->registers.hl, --dec);
  set_if_zero(&gb->registers, dec);
  set_substract_flag(&gb->registers);
  set_if_no_borrow_half_carry(&gb->registers, dec + 1, 1);
}

void    instr_add_hl_bc(t_gameboy *gb)
{
  uint16_t        lo = gb->registers.hl;
  uint16_t        ro = gb->registers.bc;

  gb->registers.hl += ro;
  unset_substract_flag(&gb->registers);
  set_if_carry_bit15(&gb->registers, lo, ro, gb->registers.hl);
  set_if_half_carry_bit11(&gb->registers, lo, ro);
}

void    instr_add_hl_de(t_gameboy *gb)
{
  uint16_t        lo = gb->registers.hl;
  uint16_t        ro = gb->registers.de;

  gb->registers.hl += ro;
  unset_substract_flag(&gb->registers);
  set_if_carry_bit15(&gb->registers, lo, ro, gb->registers.hl);
  set_if_half_carry_bit11(&gb->registers, lo, ro);
}

void    instr_add_hl_hl(t_gameboy *gb)
{
  uint16_t        lo = gb->registers.hl;
  uint16_t        ro = lo;

  gb->registers.hl += ro;
  unset_substract_flag(&gb->registers);
  set_if_carry_bit15(&gb->registers, lo, ro, gb->registers.hl);
  set_if_half_carry_bit11(&gb->registers, lo, ro);
}

void    instr_add_hl_sp(t_gameboy *gb)
{
  uint16_t        lo = gb->registers.hl;
  uint16_t        ro = gb->registers.sp;

  gb->registers.hl += ro;
  unset_substract_flag(&gb->registers);
  set_if_carry_bit15(&gb->registers, lo, ro, gb->registers.hl);
  set_if_half_carry_bit11(&gb->registers, lo, ro);
}

/*
** TODO: verify the c and hc flags settings.
*/
void    instr_add_sp_r8(t_gameboy *gb)
{
  uint16_t        lo = gb->registers.sp;
  char                  ro = gb->instruction.op_len8;

  gb->registers.sp += ro;
  unset_substract_flag(&gb->registers);
  unset_zero_flag(&gb->registers);
  set_if_carry_bit15(&gb->registers, lo, ro, gb->registers.sp);
  set_if_half_carry_bit11(&gb->registers, lo, ro);
}

void    instr_inc_bc(t_gameboy *gb)
{
  ++gb->registers.bc;
}

void    instr_inc_de(t_gameboy *gb)
{
  ++gb->registers.de;
}

void    instr_inc_hl(t_gameboy *gb)
{
  ++gb->registers.hl;
}

void    instr_inc_sp(t_gameboy *gb)
{
  ++gb->registers.sp;
}

void    instr_dec_bc(t_gameboy *gb)
{
  --gb->registers.bc;
}

void    instr_dec_de(t_gameboy *gb)
{
  --gb->registers.de;
}

void    instr_dec_hl(t_gameboy *gb)
{
  --gb->registers.hl;
}

void    instr_dec_sp(t_gameboy *gb)
{
  --gb->registers.sp;
}

void    instr_daa(t_gameboy *gb)
{
  if (get_half_carry_flag(gb->registers.f) || (gb->registers.a & 0x0F) > 0x9)
      gb->registers.a += 0x06;
  if (get_carry_flag(gb->registers.f) || (gb->registers.a & 0xF0) > 0x90)
    {
      gb->registers.a += 0x60;
      set_carry_flag(&gb->registers);
    }
  else
      unset_carry_flag(&gb->registers);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_half_carry_flag(&gb->registers);
}

void    instr_cpl(t_gameboy *gb)
{
  gb->registers.a = ~gb->registers.a;
  set_substract_flag(&gb->registers);
  set_half_carry_flag(&gb->registers);
}

void    instr_ccf(t_gameboy *gb)
{
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  if (get_carry_flag(gb->registers.f))
    unset_carry_flag(&gb->registers);
  else
    set_carry_flag(&gb->registers);
}

void    instr_scf(t_gameboy *gb)
{
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  set_carry_flag(&gb->registers);
}

void    instr_nop(t_gameboy *gb)
{
  (void)gb;
}

void    instr_halt(t_gameboy *gb)
{
  (void)gb;
  printf("Unimplemendted HALT\n");
#warning "TODO: implement halt"
}

void    instr_stop(t_gameboy *gb)
{
  (void)gb;
  printf("Unimplemendted STOP\n");
#warning "TODO: implement stop"
}

// TODO: "Manage Interupts in main program"
void    instr_di(t_gameboy *gb)
{
  gb->interrupts.master = false;
}

void    instr_ei(t_gameboy *gb)
{
  gb->interrupts.master = true;
}

void    instr_rlca(t_gameboy *gb)
{
  bool                  bit = IS_NEG(gb->registers.a);

  gb->registers.a = (gb->registers.a << 1) | bit;
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, bit);
}

void    instr_rla(t_gameboy *gb)
{
  bool                  head = IS_NEG(gb->registers.a);

  gb->registers.a = (gb->registers.a << 1) | get_carry_flag(gb->registers.f);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, head);
}

void    instr_rrca(t_gameboy *gb)
{
  bool                  tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1) | (tail << 7);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void    instr_rra(t_gameboy *gb)
{
  bool                  tail = (gb->registers.a & 0x01);

  gb->registers.a = (gb->registers.a >> 1) | (get_carry_flag(gb->registers.f) << 7);
  set_if_zero(&gb->registers, gb->registers.a);
  unset_substract_flag(&gb->registers);
  unset_half_carry_flag(&gb->registers);
  attr_carry_flag(&gb->registers, tail);
}

void    instr_jp_a16(t_gameboy *gb)
{
  gb->registers.pc = gb->instruction.op_len16;
}

void    instr_jp_nz_a16(t_gameboy *gb)
{
  if (!get_zero_flag(gb->registers.f)) {
      gb->registers.pc = gb->instruction.op_len16;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jp_z_a16(t_gameboy *gb)
{
  if (get_zero_flag(gb->registers.f)) {
      gb->registers.pc = gb->instruction.op_len16;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jp_nc_a16(t_gameboy *gb)
{
  if (!get_carry_flag(gb->registers.f)) {
      gb->registers.pc = gb->instruction.op_len16;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jp_c_a16(t_gameboy *gb)
{
  if (get_carry_flag(gb->registers.f)) {
      gb->registers.pc = gb->instruction.op_len16;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jp_hlp(t_gameboy *gb)
{
  gb->registers.pc = gb->registers.hl;
}

void    instr_jr_r8(t_gameboy *gb)
{
  gb->registers.pc += gb->instruction.op_len8;
}

void    instr_jr_nz_r8(t_gameboy *gb)
{
  if (!get_zero_flag(gb->registers.f)) {
      gb->registers.pc += gb->instruction.op_len8;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jr_z_r8(t_gameboy *gb)
{
  if (get_zero_flag(gb->registers.f)) {
      gb->registers.pc += gb->instruction.op_len8;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jr_nc_r8(t_gameboy *gb)
{
  if (!get_carry_flag(gb->registers.f)) {
      gb->registers.pc += gb->instruction.op_len8;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_jr_c_r8(t_gameboy *gb)
{
  if (get_carry_flag(gb->registers.f)) {
      gb->registers.pc += gb->instruction.op_len8;
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_call_a16(t_gameboy *gb)
{
  uint16_t        addr = gb->instruction.op_len16;

  push_word(gb, gb->registers.pc);
  gb->registers.pc = addr;
}

void    instr_call_nz_a16(t_gameboy *gb)
{
  if (get_zero_flag(gb->registers.f))
    return ;
  uint16_t        addr = gb->instruction.op_len16;

  push_word(gb, gb->registers.pc);
  gb->registers.pc = addr;
  gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
}

void    instr_call_z_a16(t_gameboy *gb)
{
  if (!get_zero_flag(gb->registers.f))
    return ;
  uint16_t        addr = gb->instruction.op_len16;

  push_word(gb, gb->registers.pc);
  gb->registers.pc = addr;
  gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
}

void    instr_call_nc_a16(t_gameboy *gb)
{
  if (get_carry_flag(gb->registers.f))
    return ;
  uint16_t        addr = gb->instruction.op_len16;

  push_word(gb, gb->registers.pc);
  gb->registers.pc = addr;
  gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
}

void    instr_call_c_a16(t_gameboy *gb)
{
  if (!get_carry_flag(gb->registers.f))
    return ;
  uint16_t        addr = gb->instruction.op_len16;

  push_word(gb, gb->registers.pc);
  gb->registers.pc = addr;
  gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
}

void    rst_base(t_gameboy *gb, uint16_t value)
{
  push_word(gb, gb->registers.pc);
  gb->registers.pc = value;
}

void    instr_rst_00(t_gameboy *gb)
{
  rst_base(gb, 0x00);
}

void    instr_rst_08(t_gameboy *gb)
{
  rst_base(gb, 0x08);
}

void    instr_rst_10(t_gameboy *gb)
{
  rst_base(gb, 0x10);
}

void    instr_rst_18(t_gameboy *gb)
{
  rst_base(gb, 0x18);
}

void    instr_rst_20(t_gameboy *gb)
{
  rst_base(gb, 0x20);
}

void    instr_rst_28(t_gameboy *gb)
{
  rst_base(gb, 0x28);
}

void    instr_rst_30(t_gameboy *gb)
{
  rst_base(gb, 0x30);
}

void    instr_rst_38(t_gameboy *gb)
{
  rst_base(gb, 0x38);
}

void    instr_ret(t_gameboy *gb)
{
  gb->registers.pc = pop_word(gb);
}

void    instr_ret_nz(t_gameboy *gb)
{
  if (!get_zero_flag(gb->registers.f)) {
      gb->registers.pc = pop_word(gb);
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_ret_z(t_gameboy *gb)
{
  if (get_zero_flag(gb->registers.f)) {
      gb->registers.pc = pop_word(gb);
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_ret_nc(t_gameboy *gb)
{
  if (!get_carry_flag(gb->registers.f)) {
      gb->registers.pc = pop_word(gb);
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_ret_c(t_gameboy *gb)
{
  if (get_carry_flag(gb->registers.f)) {
      gb->registers.pc = pop_word(gb);
      gb->instruction.cycles = g_instructions[gb->instruction.opcode].cond_taken_cycles;
  }
}

void    instr_reti(t_gameboy *gb)
{
  gb->registers.pc = pop_word(gb);
  gb->interrupts.master = true;
}

void    instr_prefix_cb(t_gameboy *gb)
{
  (*g_cb_instructions[(uint8_t)gb->instruction.op_len8].func)(gb);
}
