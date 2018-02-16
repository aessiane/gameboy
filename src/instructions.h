#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

typedef struct s_gameboy	t_gameboy;

typedef void	(t_instruction_func)(t_gameboy *gb);

/*
** - instr_length : length of the whole instruction in bytes
*/
typedef struct		s_instruction
{
  char const		*debug;
  t_instruction_func	*func;
  unsigned char		instr_length;
  unsigned char		nb_cycles;
  unsigned char		cond_taken_cycles;
}			t_instruction;

# define NB_INSTRUCTIONS	245
# define MAX_INSTRUCTION	0xFF

extern const t_instruction	g_instructions[MAX_INSTRUCTION + 1];

t_instruction_func	instr_ld_b_d8;
t_instruction_func	instr_ld_c_d8;
t_instruction_func	instr_ld_d_d8;
t_instruction_func	instr_ld_e_d8;
t_instruction_func	instr_ld_h_d8;
t_instruction_func	instr_ld_l_d8;
t_instruction_func	instr_ld_a_a;
t_instruction_func	instr_ld_a_b;
t_instruction_func	instr_ld_a_c;
t_instruction_func	instr_ld_a_d;
t_instruction_func	instr_ld_a_e;
t_instruction_func	instr_ld_a_h;
t_instruction_func	instr_ld_a_l;
t_instruction_func	instr_ld_a_hl;
t_instruction_func	instr_ld_b_b;
t_instruction_func	instr_ld_b_c;
t_instruction_func	instr_ld_b_d;
t_instruction_func	instr_ld_b_e;
t_instruction_func	instr_ld_b_h;
t_instruction_func	instr_ld_b_l;
t_instruction_func	instr_ld_b_hl;
t_instruction_func	instr_ld_c_b;
t_instruction_func	instr_ld_c_c;
t_instruction_func	instr_ld_c_d;
t_instruction_func	instr_ld_c_e;
t_instruction_func	instr_ld_c_h;
t_instruction_func	instr_ld_c_l;
t_instruction_func	instr_ld_c_hl;
t_instruction_func	instr_ld_d_b;
t_instruction_func	instr_ld_d_c;
t_instruction_func	instr_ld_d_d;
t_instruction_func	instr_ld_d_e;
t_instruction_func	instr_ld_d_h;
t_instruction_func	instr_ld_d_l;
t_instruction_func	instr_ld_d_hl;
t_instruction_func	instr_ld_e_b;
t_instruction_func	instr_ld_e_c;
t_instruction_func	instr_ld_e_d;
t_instruction_func	instr_ld_e_e;
t_instruction_func	instr_ld_e_h;
t_instruction_func	instr_ld_e_l;
t_instruction_func	instr_ld_e_hl;
t_instruction_func	instr_ld_h_b;
t_instruction_func	instr_ld_h_c;
t_instruction_func	instr_ld_h_d;
t_instruction_func	instr_ld_h_e;
t_instruction_func	instr_ld_h_h;
t_instruction_func	instr_ld_h_l;
t_instruction_func	instr_ld_h_hl;
t_instruction_func	instr_ld_l_b;
t_instruction_func	instr_ld_l_c;
t_instruction_func	instr_ld_l_d;
t_instruction_func	instr_ld_l_e;
t_instruction_func	instr_ld_l_h;
t_instruction_func	instr_ld_l_l;
t_instruction_func	instr_ld_l_hl;
t_instruction_func	instr_ld_hl_b;
t_instruction_func	instr_ld_hl_c;
t_instruction_func	instr_ld_hl_d;
t_instruction_func	instr_ld_hl_e;
t_instruction_func	instr_ld_hl_h;
t_instruction_func	instr_ld_hl_l;
t_instruction_func	instr_ld_hl_d8;
t_instruction_func	instr_ld_a_bcp;
t_instruction_func	instr_ld_a_dep;
t_instruction_func	instr_ld_a_a16;
t_instruction_func	instr_ld_a_d8;
t_instruction_func	instr_ld_b_a;
t_instruction_func	instr_ld_c_a;
t_instruction_func	instr_ld_d_a;
t_instruction_func	instr_ld_e_a;
t_instruction_func	instr_ld_h_a;
t_instruction_func	instr_ld_l_a;
t_instruction_func	instr_ld_bcp_a;
t_instruction_func	instr_ld_dep_a;
t_instruction_func	instr_ld_hlp_a;
t_instruction_func	instr_ld_a16_a;
t_instruction_func	instr_ld_a_cp_ff00;
t_instruction_func	instr_ld_cp_a_ff00;
t_instruction_func	instr_ldd_a_hlp;
t_instruction_func	instr_ldd_hlp_a;
t_instruction_func	instr_ldi_a_hlp;
t_instruction_func	instr_ldi_hlp_a;
t_instruction_func	instr_ldh_d8_a;
t_instruction_func	instr_ldh_a_d8;
t_instruction_func	instr_ld_bc_d16;
t_instruction_func	instr_ld_de_d16;
t_instruction_func	instr_ld_hl_d16;
t_instruction_func	instr_ld_sp_d16;
t_instruction_func	instr_ld_sp_hl;
t_instruction_func	instr_ldhl_sp_d8;
t_instruction_func	instr_ld_d16_sp;
t_instruction_func	instr_push_af;
t_instruction_func	instr_push_bc;
t_instruction_func	instr_push_de;
t_instruction_func	instr_push_hl;
t_instruction_func	instr_pop_af;
t_instruction_func	instr_pop_bc;
t_instruction_func	instr_pop_de;
t_instruction_func	instr_pop_hl;
t_instruction_func	instr_add_a_a;
t_instruction_func	instr_add_a_b;
t_instruction_func	instr_add_a_c;
t_instruction_func	instr_add_a_d;
t_instruction_func	instr_add_a_e;
t_instruction_func	instr_add_a_h;
t_instruction_func	instr_add_a_l;
t_instruction_func	instr_add_a_hlp;
t_instruction_func	instr_add_a_d8;
t_instruction_func	instr_adc_a_a;
t_instruction_func	instr_adc_a_b;
t_instruction_func	instr_adc_a_c;
t_instruction_func	instr_adc_a_d;
t_instruction_func	instr_adc_a_e;
t_instruction_func	instr_adc_a_h;
t_instruction_func	instr_adc_a_l;
t_instruction_func	instr_adc_a_hlp;
t_instruction_func	instr_adc_a_d8;
t_instruction_func	instr_sub_a_a;
t_instruction_func	instr_sub_a_b;
t_instruction_func	instr_sub_a_c;
t_instruction_func	instr_sub_a_d;
t_instruction_func	instr_sub_a_e;
t_instruction_func	instr_sub_a_h;
t_instruction_func	instr_sub_a_l;
t_instruction_func	instr_sub_a_hlp;
t_instruction_func	instr_sub_a_d8;
t_instruction_func	instr_sbc_a_a;
t_instruction_func	instr_sbc_a_b;
t_instruction_func	instr_sbc_a_c;
t_instruction_func	instr_sbc_a_d;
t_instruction_func	instr_sbc_a_e;
t_instruction_func	instr_sbc_a_h;
t_instruction_func	instr_sbc_a_l;
t_instruction_func	instr_sbc_a_hlp;
t_instruction_func	instr_sbc_a_d8;
t_instruction_func	instr_and_a_a;
t_instruction_func	instr_and_a_b;
t_instruction_func	instr_and_a_c;
t_instruction_func	instr_and_a_d;
t_instruction_func	instr_and_a_e;
t_instruction_func	instr_and_a_h;
t_instruction_func	instr_and_a_l;
t_instruction_func	instr_and_a_hlp;
t_instruction_func	instr_and_a_d8;
t_instruction_func	instr_or_a_a;
t_instruction_func	instr_or_a_b;
t_instruction_func	instr_or_a_c;
t_instruction_func	instr_or_a_d;
t_instruction_func	instr_or_a_e;
t_instruction_func	instr_or_a_h;
t_instruction_func	instr_or_a_l;
t_instruction_func	instr_or_a_hlp;
t_instruction_func	instr_or_a_d8;
t_instruction_func	instr_xor_a_a;
t_instruction_func	instr_xor_a_b;
t_instruction_func	instr_xor_a_c;
t_instruction_func	instr_xor_a_d;
t_instruction_func	instr_xor_a_e;
t_instruction_func	instr_xor_a_h;
t_instruction_func	instr_xor_a_l;
t_instruction_func	instr_xor_a_hlp;
t_instruction_func	instr_xor_a_d8;
t_instruction_func	instr_cp_a_a;
t_instruction_func	instr_cp_a_b;
t_instruction_func	instr_cp_a_c;
t_instruction_func	instr_cp_a_d;
t_instruction_func	instr_cp_a_e;
t_instruction_func	instr_cp_a_h;
t_instruction_func	instr_cp_a_l;
t_instruction_func	instr_cp_a_hlp;
t_instruction_func	instr_cp_a_d8;
t_instruction_func	instr_inc_a_a;
t_instruction_func	instr_inc_a_b;
t_instruction_func	instr_inc_a_c;
t_instruction_func	instr_inc_a_d;
t_instruction_func	instr_inc_a_e;
t_instruction_func	instr_inc_a_h;
t_instruction_func	instr_inc_a_l;
t_instruction_func	instr_inc_a_hlp;
t_instruction_func	instr_dec_a_a;
t_instruction_func	instr_dec_a_b;
t_instruction_func	instr_dec_a_c;
t_instruction_func	instr_dec_a_d;
t_instruction_func	instr_dec_a_e;
t_instruction_func	instr_dec_a_h;
t_instruction_func	instr_dec_a_l;
t_instruction_func	instr_dec_a_hlp;
t_instruction_func	instr_add_hl_bc;
t_instruction_func	instr_add_hl_de;
t_instruction_func	instr_add_hl_hl;
t_instruction_func	instr_add_hl_sp;
t_instruction_func	instr_add_sp_r8;
t_instruction_func	instr_inc_bc;
t_instruction_func	instr_inc_de;
t_instruction_func	instr_inc_hl;
t_instruction_func	instr_inc_sp;
t_instruction_func	instr_dec_bc;
t_instruction_func	instr_dec_de;
t_instruction_func	instr_dec_hl;
t_instruction_func	instr_dec_sp;
t_instruction_func	instr_daa;
t_instruction_func	instr_cpl;
t_instruction_func	instr_ccf;
t_instruction_func	instr_scf;
t_instruction_func	instr_nop;
t_instruction_func	instr_halt;
t_instruction_func	instr_stop;
t_instruction_func	instr_di;
t_instruction_func	instr_ei;
t_instruction_func	instr_rlca;
t_instruction_func	instr_rla;
t_instruction_func	instr_rrca;
t_instruction_func	instr_rra;
t_instruction_func	instr_jp_a16;
t_instruction_func	instr_jp_nz_a16;
t_instruction_func	instr_jp_z_a16;
t_instruction_func	instr_jp_nc_a16;
t_instruction_func	instr_jp_c_a16;
t_instruction_func	instr_jp_hlp;
t_instruction_func	instr_jr_r8;
t_instruction_func	instr_jr_nz_r8;
t_instruction_func	instr_jr_z_r8;
t_instruction_func	instr_jr_nc_r8;
t_instruction_func	instr_jr_c_r8;
t_instruction_func	instr_call_a16;
t_instruction_func	instr_call_nz_a16;
t_instruction_func	instr_call_z_a16;
t_instruction_func	instr_call_nc_a16;
t_instruction_func	instr_call_c_a16;
t_instruction_func	instr_rst_00;
t_instruction_func	instr_rst_08;
t_instruction_func	instr_rst_10;
t_instruction_func	instr_rst_18;
t_instruction_func	instr_rst_20;
t_instruction_func	instr_rst_28;
t_instruction_func	instr_rst_30;
t_instruction_func	instr_rst_38;
t_instruction_func	instr_ret;
t_instruction_func	instr_ret_nz;
t_instruction_func	instr_ret_z;
t_instruction_func	instr_ret_nc;
t_instruction_func	instr_ret_c;
t_instruction_func	instr_reti;
t_instruction_func	instr_prefix_cb;

#endif /* !INSTRUCTION_H_ */
