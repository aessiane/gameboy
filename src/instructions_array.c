#include "instructions.h"

const t_instruction		g_instructions[MAX_INSTRUCTION + 1] = {
    /*
    **                              8-BIT LOADS
    ** _________________________________________________________________________
    */

    // LD nn, d8 : put value nn into d8.
    [0x06] = {"LD B, [0x%02hhX]",	&instr_ld_b_d8,		1,	8, 0},
    [0x0E] = {"LD C, [0x%02hhX]",	&instr_ld_c_d8,		1,	8, 0},
    [0x16] = {"LD D, [0x%02hhX]",	&instr_ld_d_d8,		1,	8, 0},
    [0x1E] = {"LD E, [0x%02hhX]",	&instr_ld_e_d8,		1,	8, 0},
    [0x26] = {"LD H, [0x%02hhX]",	&instr_ld_h_d8,		1,	8, 0},
    [0x2E] = {"LD L, [0x%02hhX]",	&instr_ld_l_d8,		1,	8, 0},

    // LD r1, r2 : put value r2 into r1.
    [0x7F] = {"LD A, A",		&instr_ld_a_a,		0,	4, 0},
    [0x78] = {"LD A, B",		&instr_ld_a_b,		0,	4, 0},
    [0x79] = {"LD A, C",		&instr_ld_a_c,		0,	4, 0},
    [0x7A] = {"LD A, D",		&instr_ld_a_d,		0,	4, 0},
    [0x7B] = {"LD A, E",		&instr_ld_a_e,		0,	4, 0},
    [0x7C] = {"LD A, H",		&instr_ld_a_h,		0,	4, 0},
    [0x7D] = {"LD A, L",		&instr_ld_a_l,		0,	4, 0},
    [0x7E] = {"LD A, (HL)",		&instr_ld_a_hl,		0,	8, 0},

    [0x40] = {"LD B, B",		&instr_ld_b_b,		0,	4, 0},
    [0x41] = {"LD B, C",		&instr_ld_b_c,		0,	4, 0},
    [0x42] = {"LD B, D",		&instr_ld_b_d,		0,	4, 0},
    [0x43] = {"LD B, E",		&instr_ld_b_e,		0,	4, 0},
    [0x44] = {"LD B, H",		&instr_ld_b_h,		0,	4, 0},
    [0x45] = {"LD B, L",		&instr_ld_b_l,		0,	4, 0},
    [0x46] = {"LD B, (HL)",		&instr_ld_b_hl,		0,	8, 0},

    [0x48] = {"LD C, B",		&instr_ld_c_b,		0,	4, 0},
    [0x49] = {"LD C, C",		&instr_ld_c_c,		0,	4, 0},
    [0x4A] = {"LD C, D",		&instr_ld_c_d,		0,	4, 0},
    [0x4B] = {"LD C, E",		&instr_ld_c_e,		0,	4, 0},
    [0x4C] = {"LD C, H",		&instr_ld_c_h,		0,	4, 0},
    [0x4D] = {"LD C, L",		&instr_ld_c_l,		0,	4, 0},
    [0x4E] = {"LD C, (HL)",		&instr_ld_c_hl,		0,	8, 0},

    [0x50] = {"LD D, B",		&instr_ld_d_b,		0,	4, 0},
    [0x51] = {"LD D, C",		&instr_ld_d_c,		0,	4, 0},
    [0x52] = {"LD D, D",		&instr_ld_d_d,		0,	4, 0},
    [0x53] = {"LD D, E",		&instr_ld_d_e,		0,	4, 0},
    [0x54] = {"LD D, H",		&instr_ld_d_h,		0,	4, 0},
    [0x55] = {"LD D, L",		&instr_ld_d_l,		0,	4, 0},
    [0x56] = {"LD D, (HL)",		&instr_ld_d_hl,		0,	8, 0},

    [0x58] = {"LD E, B",		&instr_ld_e_b,		0,	4, 0},
    [0x59] = {"LD E, C",		&instr_ld_e_c,		0,	4, 0},
    [0x5A] = {"LD E, D",		&instr_ld_e_d,		0,	4, 0},
    [0x5B] = {"LD E, E",		&instr_ld_e_e,		0,	4, 0},
    [0x5C] = {"LD E, H",		&instr_ld_e_h,		0,	4, 0},
    [0x5D] = {"LD E, L",		&instr_ld_e_l,		0,	4, 0},
    [0x5E] = {"LD E, (HL)",		&instr_ld_e_hl,		0,	8, 0},

    [0x60] = {"LD H, B",		&instr_ld_h_b,		0,	4, 0},
    [0x61] = {"LD H, C",		&instr_ld_h_c,		0,	4, 0},
    [0x62] = {"LD H, D",		&instr_ld_h_d,		0,	4, 0},
    [0x63] = {"LD H, E",		&instr_ld_h_e,		0,	4, 0},
    [0x64] = {"LD H, H",		&instr_ld_h_h,		0,	4, 0},
    [0x65] = {"LD H, L",		&instr_ld_h_l,		0,	4, 0},
    [0x66] = {"LD H, (HL)",		&instr_ld_h_hl,		0,	8, 0},

    [0x68] = {"LD L, B",		&instr_ld_l_b,		0,	4, 0},
    [0x69] = {"LD L, C",		&instr_ld_l_c,		0,	4, 0},
    [0x6A] = {"LD L, D",		&instr_ld_l_d,		0,	4, 0},
    [0x6B] = {"LD L, E",		&instr_ld_l_e,		0,	4, 0},
    [0x6C] = {"LD L, H",		&instr_ld_l_h,		0,	4, 0},
    [0x6D] = {"LD L, L",		&instr_ld_l_l,		0,	4, 0},
    [0x6E] = {"LD L, (HL)",		&instr_ld_l_hl,		0,	8, 0},

    [0x70] = {"LD (HL), B",		&instr_ld_hl_b,		0,	8, 0},
    [0x71] = {"LD (HL), C",		&instr_ld_hl_c,		0,	8, 0},
    [0x72] = {"LD (HL), D",		&instr_ld_hl_d,		0,	8, 0},
    [0x73] = {"LD (HL), E",		&instr_ld_hl_e,		0,	8, 0},
    [0x74] = {"LD (HL), H",		&instr_ld_hl_h,		0,	8, 0},
    [0x75] = {"LD (HL), L",		&instr_ld_hl_l,		0,	8, 0},
    [0x36] = {"LD (HL), [0x%02hhX]",	&instr_ld_hl_d8,	1,	12, 0},

    // LD A, n : put value n into A.
    [0x0A] = {"LD A, (BC)",		&instr_ld_a_bcp,	0,	8, 0},
    [0x1A] = {"LD A, (DE)",		&instr_ld_a_dep,	0,	8, 0},
    [0xFA] = {"LD A, ([0x%04hX])",	&instr_ld_a_a16,	2,	16, 0},
    [0x3E] = {"LD A, [0x%02hhX]",	&instr_ld_a_d8,		1,	8, 0},

    // LD n, A : put value A into n.
    [0x47] = {"LD B, A",		&instr_ld_b_a,		0,	4, 0},
    [0x4F] = {"LD C, A",		&instr_ld_c_a,		0,	4, 0},
    [0x57] = {"LD D, A",		&instr_ld_d_a,		0,	4, 0},
    [0x5F] = {"LD E, A",		&instr_ld_e_a,		0,	4, 0},
    [0x67] = {"LD H, A",		&instr_ld_h_a,		0,	4, 0},
    [0x6F] = {"LD L, A",		&instr_ld_l_a,		0,	4, 0},
    [0x02] = {"LD (BC), A",		&instr_ld_bcp_a,	0,	8, 0},
    [0x12] = {"LD (DE), A",		&instr_ld_dep_a,	0,	8, 0},
    [0x77] = {"LD (HL), A",		&instr_ld_hlp_a,	0,	8, 0},
    [0xEA] = {"LD ([0x%04hX]), A",	&instr_ld_a16_a,	2,	16, 0},

    // LD A, (C) : put value at address $FF00 + register C into A.
    // Same as : LD A, ($FF00 + C)
    [0xF2] = {"LD A, (C)",		&instr_ld_a_cp_ff00,	0,	8, 0},

    // LD (C), A : put A into address $FF00 + register C.
    [0xE2] = {"LD (C), A",		&instr_ld_cp_a_ff00,	0,	8, 0},

    // LDD A, (HL) : put value at address HL into A. Decrement HL.
    [0x3A] = {"LDD A, (HL)",		&instr_ldd_a_hlp,	0,	8, 0},

    // LDD (HL), A : put A into memory address HL. Decrement HL.
    [0x32] = {"LDD (HL), A",		&instr_ldd_hlp_a,	0,	8, 0},

    // LDI A, (HL) : put value at address HL into A. Increment HL.
    [0x2A] = {"LDI A, (HL)",		&instr_ldi_a_hlp,	0,	8, 0},

    // LDI (HL), A : put A into memory address HL. Increment HL.
    [0x22] = {"LDI (HL), A",		&instr_ldi_hlp_a,	0,	8, 0},

    // LDH (d8), A : put A into memory address $FF00 + d8.
    [0xE0] = {"LDH ([0x%02hhX]), A",	&instr_ldh_d8_a,	1,	12, 0},

    // LDH A, (d8) : put memory address $FF00 + d8 into A.
    [0xF0] = {"LDH A, ([0x%02hhX])",	&instr_ldh_a_d8,	1,	12, 0},

    /*
    **                              16-BIT LOADS
    ** _________________________________________________________________________
    */

    // LD r, d16 : put value d16 into r.
    [0x01] = {"LD BC, [0x%04hX]",	&instr_ld_bc_d16,	2,	12, 0},
    [0x11] = {"LD DE, [0x%04hX]",	&instr_ld_de_d16,	2,	12, 0},
    [0x21] = {"LD HL, [0x%04hX]",	&instr_ld_hl_d16,	2,	12, 0},
    [0x31] = {"LD SP, [0x%04hX]",	&instr_ld_sp_d16,	2,	12, 0},

    // LD SP, HL : put HL into SP.
    [0xF9] = {"LD SP, HL",		&instr_ld_sp_hl,	0,	8, 0},

    // LDHL SP, d8 : put SP + d8 effective address into HL.
    [0xF8] = {"LDHL SP, [0x%02hhX]",	&instr_ldhl_sp_d8,	1,	12, 0},

    // LD d16, SP : put SP at address d16.
    [0x08] = {"LD (d16), SP",		&instr_ld_d16_sp,	2,	20, 0},

    // PUSH rr : push register pair rr onto stack. Decrement SP twice.
    [0xF5] = {"PUSH AF",		&instr_push_af,		0,	16, 0},
    [0xC5] = {"PUSH BC",		&instr_push_bc,		0,	16, 0},
    [0xD5] = {"PUSH DE",		&instr_push_de,		0,	16, 0},
    [0xE5] = {"PUSH HL",		&instr_push_hl,		0,	16, 0},

    // POP r : pop two bytes off stack into register pair r. Increment SP twice.
    [0xF1] = {"POP AF",			&instr_pop_af,		0,	12, 0},
    [0xC1] = {"POP BC",			&instr_pop_bc,		0,	12, 0},
    [0xD1] = {"POP DE",			&instr_pop_de,		0,	12, 0},
    [0xE1] = {"POP HL",			&instr_pop_hl,		0,	12, 0},

    /*
    **                              8-BIT ALU
    ** ___________________________________________________________	_____________
    */

    // ADD A, r : add r to A.
    [0x87] = {"ADD A, A",		&instr_add_a_a,		0,	4, 0},
    [0x80] = {"ADD A, B",		&instr_add_a_b,		0,	4, 0},
    [0x81] = {"ADD A, C",		&instr_add_a_c,		0,	4, 0},
    [0x82] = {"ADD A, D",		&instr_add_a_d,		0,	4, 0},
    [0x83] = {"ADD A, E",		&instr_add_a_e,		0,	4, 0},
    [0x84] = {"ADD A, H",		&instr_add_a_h,		0,	4, 0},
    [0x85] = {"ADD A, L",		&instr_add_a_l,		0,	4, 0},
    [0x86] = {"ADD A, (HL)",		&instr_add_a_hlp,	0,	8, 0},
    [0xC6] = {"ADD A, [0x%02hhX]",	&instr_add_a_d8,	1,	8, 0},

    // ADC A, r : add r + Carry flag to A.
    [0x8F] = {"ADC A, A",		&instr_adc_a_a,		0,	4, 0},
    [0x88] = {"ADC A, B",		&instr_adc_a_b,		0,	4, 0},
    [0x89] = {"ADC A, C",		&instr_adc_a_c,		0,	4, 0},
    [0x8A] = {"ADC A, D",		&instr_adc_a_d,		0,	4, 0},
    [0x8B] = {"ADC A, E",		&instr_adc_a_e,		0,	4, 0},
    [0x8C] = {"ADC A, H",		&instr_adc_a_h,		0,	4, 0},
    [0x8D] = {"ADC A, L",		&instr_adc_a_l,		0,	4, 0},
    [0x8E] = {"ADC A, (HL)",		&instr_adc_a_hlp,	0,	8, 0},
    [0xCE] = {"ADC A, [0x%02hhX]",	&instr_adc_a_d8,	1,	8, 0},

    // SUB r : substract r to A.
    [0x97] = {"SUB A, A",		&instr_sub_a_a,		0,	4, 0},
    [0x90] = {"SUB A, B",		&instr_sub_a_b,		0,	4, 0},
    [0x91] = {"SUB A, C",		&instr_sub_a_c,		0,	4, 0},
    [0x92] = {"SUB A, D",		&instr_sub_a_d,		0,	4, 0},
    [0x93] = {"SUB A, E",		&instr_sub_a_e,		0,	4, 0},
    [0x94] = {"SUB A, H",		&instr_sub_a_h,		0,	4, 0},
    [0x95] = {"SUB A, L",		&instr_sub_a_l,		0,	4, 0},
    [0x96] = {"SUB A, (HL)",		&instr_sub_a_hlp,	0,	8, 0},
    [0xD6] = {"SUB A, [0x%02hhX]",	&instr_sub_a_d8,	1,	8, 0},

    // SBC A, r : substract r + Carry flag from A.
    [0x9F] = {"SBC A, A",		&instr_sbc_a_a,		0,	4, 0},
    [0x98] = {"SBC A, B",		&instr_sbc_a_b,		0,	4, 0},
    [0x99] = {"SBC A, C",		&instr_sbc_a_c,		0,	4, 0},
    [0x9A] = {"SBC A, D",		&instr_sbc_a_d,		0,	4, 0},
    [0x9B] = {"SBC A, E",		&instr_sbc_a_e,		0,	4, 0},
    [0x9C] = {"SBC A, H",		&instr_sbc_a_h,		0,	4, 0},
    [0x9D] = {"SBC A, L",		&instr_sbc_a_l,		0,	4, 0},
    [0x9E] = {"SBC A, (HL)",		&instr_sbc_a_hlp,	0,	8, 0},
    [0xDE] = {"SBC A, [0x%02hhX]",	&instr_sbc_a_d8,	1,	8, 0}, // ATTENTION, indefini dans le GameBoy CPU Manual

    // AND r : logically AND r with A, result in A.
    [0xA7] = {"AND A, A",		&instr_and_a_a,		0,	4, 0},
    [0xA0] = {"AND A, B",		&instr_and_a_b,		0,	4, 0},
    [0xA1] = {"AND A, C",		&instr_and_a_c,		0,	4, 0},
    [0xA2] = {"AND A, D",		&instr_and_a_d,		0,	4, 0},
    [0xA3] = {"AND A, E",		&instr_and_a_e,		0,	4, 0},
    [0xA4] = {"AND A, H",		&instr_and_a_h,		0,	4, 0},
    [0xA5] = {"AND A, L",		&instr_and_a_l,		0,	4, 0},
    [0xA6] = {"AND A, (HL)",		&instr_and_a_hlp,	0,	8, 0},
    [0xE6] = {"AND A, [0x%02hhX]",	&instr_and_a_d8,	1,	8, 0},

    // OR r : logical OR r with A, result in A.
    [0xB7] = {"OR A, A",		&instr_or_a_a,		0,	4, 0},
    [0xB0] = {"OR A, B",		&instr_or_a_b,		0,	4, 0},
    [0xB1] = {"OR A, C",		&instr_or_a_c,		0,	4, 0},
    [0xB2] = {"OR A, D",		&instr_or_a_d,		0,	4, 0},
    [0xB3] = {"OR A, E",		&instr_or_a_e,		0,	4, 0},
    [0xB4] = {"OR A, H",		&instr_or_a_h,		0,	4, 0},
    [0xB5] = {"OR A, L",		&instr_or_a_l,		0,	4, 0},
    [0xB6] = {"OR A, (HL)",		&instr_or_a_hlp,		0,	8, 0},
    [0xF6] = {"OR A, [0x%02hhX]",	&instr_or_a_d8,		1,	8, 0},

    // XOR r : logical XOR r with A, result in A.
    [0xAF] = {"XOR A, A",		&instr_xor_a_a,		0,	4, 0},
    [0xA8] = {"XOR A, B",		&instr_xor_a_b,		0,	4, 0},
    [0xA9] = {"XOR A, C",		&instr_xor_a_c,		0,	4, 0},
    [0xAA] = {"XOR A, D",		&instr_xor_a_d,		0,	4, 0},
    [0xAB] = {"XOR A, E",		&instr_xor_a_e,		0,	4, 0},
    [0xAC] = {"XOR A, H",		&instr_xor_a_h,		0,	4, 0},
    [0xAD] = {"XOR A, L",		&instr_xor_a_l,		0,	4, 0},
    [0xAE] = {"XOR A, (HL)",		&instr_xor_a_hlp,	0,	8, 0},
    [0xEE] = {"XOR A, [0x%02hhX]",	&instr_xor_a_d8,	1,	8, 0},

    // CP r : compare A with n. This is A - r.
    [0xBF] = {"CP A, A",		&instr_cp_a_a,		0,	4, 0},
    [0xB8] = {"CP A, B",		&instr_cp_a_b,		0,	4, 0},
    [0xB9] = {"CP A, C",		&instr_cp_a_c,		0,	4, 0},
    [0xBA] = {"CP A, D",		&instr_cp_a_d,		0,	4, 0},
    [0xBB] = {"CP A, E",		&instr_cp_a_e,		0,	4, 0},
    [0xBC] = {"CP A, H",		&instr_cp_a_h,		0,	4, 0},
    [0xBD] = {"CP A, L",		&instr_cp_a_l,		0,	4, 0},
    [0xBE] = {"CP A, (HL)",		&instr_cp_a_hlp,	0,	8, 0},
    [0xFE] = {"CP A, [0x%02hhX]",	&instr_cp_a_d8,		1,	8, 0},

    // INC r : decrement register n.
    [0x3C] = {"INC A, A",		&instr_inc_a_a,		0,	4, 0},
    [0x04] = {"INC A, B",		&instr_inc_a_b,		0,	4, 0},
    [0x0C] = {"INC A, C",		&instr_inc_a_c,		0,	4, 0},
    [0x14] = {"INC A, D",		&instr_inc_a_d,		0,	4, 0},
    [0x1C] = {"INC A, E",		&instr_inc_a_e,		0,	4, 0},
    [0x24] = {"INC A, H",		&instr_inc_a_h,		0,	4, 0},
    [0x2C] = {"INC A, L",		&instr_inc_a_l,		0,	4, 0},
    [0x34] = {"INC A, (HL)",		&instr_inc_a_hlp,	0,	12, 0},

    // DEC r : decrement register n.
    [0x3D] = {"DEC A, A",		&instr_dec_a_a,		0,	4, 0},
    [0x05] = {"DEC A, B",		&instr_dec_a_b,		0,	4, 0},
    [0x0D] = {"DEC A, C",		&instr_dec_a_c,		0,	4, 0},
    [0x15] = {"DEC A, D",		&instr_dec_a_d,		0,	4, 0},
    [0x1D] = {"DEC A, E",		&instr_dec_a_e,		0,	4, 0},
    [0x25] = {"DEC A, H",		&instr_dec_a_h,		0,	4, 0},
    [0x2D] = {"DEC A, L",		&instr_dec_a_l,		0,	4, 0},
    [0x35] = {"DEC A, (HL)",		&instr_dec_a_hlp,	0,	12, 0},

    /*
    **                           16-BIT ARITHMETIC
    ** ________________________________________________________________________
    */

    // ADD HL, rr : add rr to HL.
    [0x09] = {"ADD HL, BC",		&instr_add_hl_bc,	0,	8, 0},
    [0x19] = {"ADD HL, DE",		&instr_add_hl_de,	0,	8, 0},
    [0x29] = {"ADD HL, HL",		&instr_add_hl_hl,	0,	8, 0},
    [0x39] = {"ADD HL, SP",		&instr_add_hl_sp,	0,	8, 0},

    // ADD SP, r8 : add r8 to SP.
    [0xE8] = {"ADD SP, [0x%02hhX]",	&instr_add_sp_r8,	1,	16, 0},

    // INC rr : increment register rr.
    [0x03] = {"INC BC",			&instr_inc_bc,		0,	8, 0},
    [0x13] = {"INC DE",			&instr_inc_de,		0,	8, 0},
    [0x23] = {"INC HL",			&instr_inc_hl,		0,	8, 0},
    [0x33] = {"INC SP",			&instr_inc_sp,		0,	8, 0},

    // DEC rr : decrement register rr.
    [0x0B] = {"DEC BC",			&instr_dec_bc,		0,	8, 0},
    [0x1B] = {"DEC DE",			&instr_dec_de,		0,	8, 0},
    [0x2B] = {"DEC HL",			&instr_dec_hl,		0,	8, 0},
    [0x3B] = {"DEC SP",			&instr_dec_sp,		0,	8, 0},

    /*
    **                               MISCELLANEOUS
    ** ________________________________________________________________________
    */

    // DAA : decimal adjust register A.
    // This instruction adjusts register A so that the correct representation
    // of Binary Coded Decimal (BCD) is obtained.
    [0x27] = {"DAA",			&instr_daa,		0,	4, 0},

    // CPL : complement A register. (Flip all bits.)
    [0x2F] = {"CPL",			&instr_cpl,		0,	4, 0},

    // CCF : complement carry flag. (Flip it.)
    [0x3F] = {"CCF",			&instr_ccf,		0,	4, 0},

    // SCF : set carry flag.
    [0x37] = {"SCF",			&instr_scf,		0,	4, 0},

    // NOP : no operation.
    [0x00] = {"NOP",			&instr_nop,		0,	4, 0},

    // HALT : power down CPU until an interrupt occurs. Use
    // this when ever possible to reduce energy consumption.
    [0x76] = {"HALT",			&instr_halt,		0,	4, 0},

    // STOP : halt CPU and LCD display until button is pressed.
    [0x10] = {"STOP",			&instr_stop,		0,	4, 0},

    // DI : disables interrupts but not immediately. Interrupts are disabled
    // after instruction after DI is executed.
    [0xF3] = {"DI",			&instr_di,		0,	4, 0},

    // EI : enable interrupts but not immediately. Interrupts are enabled
    // after instruction after EI is executed.
    [0xFB] = {"EI",			&instr_ei,		0,	4, 0},

    /*
    **                             ROTATES & SHIFTS
    ** ________________________________________________________________________
    */

    // RLCA : rotate A left. Old bit 7 to Carry flag.
    [0x07] = {"RLCA",			&instr_rlca,		0,	4, 0},

    // RLA : rotate A left through Carry flag.
    [0x17] = {"RLA",			&instr_rla,		0,	4, 0},

    // RRCA : rotate A right. Old bit 0 to Carry flag.
    [0x0F] = {"RRCA",			&instr_rrca,		0,	4, 0},

    // RRA : rotate A right through Carry flag.
    [0x1F] = {"RRA",			&instr_rra,		0,	4, 0},

    /*
    **                                   JUMPS
    ** ________________________________________________________________________
    */

    // JP a16 : jump to address a16.
    [0xC3] = {"JP [0x%04hX]",		&instr_jp_a16,		2,	16, 0},

    // JP cond, a16 : jump to address a16 if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC2] = {"JP NZ, [0x%04hX]",	&instr_jp_nz_a16,	2,	12, 16},
    [0xCA] = {"JP Z, [0x%04hX]",	&instr_jp_z_a16,	2,	12, 16},
    [0xD2] = {"JP NC, [0x%04hX]",	&instr_jp_nc_a16,	2,	12, 16},
    [0xDA] = {"JP C, [0x%04hX]",	&instr_jp_c_a16,	2,	12, 16},

    // JP (HL) : jump to address contained in HL.
    [0xE9] = {"JP (HL)",		&instr_jp_hlp,		0,	4, 0},

    // JR r8 : add n to current address and jump to it.
    [0x18] = {"JR [0x%02hhX]",		&instr_jr_r8,		1,	12, 0},

    // JR r8 : if following condition is true then add n to current address
    // and jump to it.
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0x20] = {"JR NZ, [0x%02hhX]",	&instr_jr_nz_r8,	1,	8, 12},
    [0x28] = {"JR Z, [0x%02hhX]",	&instr_jr_z_r8,		1,	8, 12},
    [0x30] = {"JR NC, [0x%02hhX]",	&instr_jr_nc_r8,	1,	8, 12},
    [0x38] = {"JR C, [0x%02hhX]",	&instr_jr_c_r8,		1,	8, 12},

    /*
    **                                   CALLS
    ** ________________________________________________________________________
    */

    // CALL a16 : push address of next instruction onto stack
    // and then jump to address a16.

    [0xCD] = {"CALL [0x%04hX]",		&instr_call_a16,	2,	12, 0},

    // CALL cond, a16 : call address a16 if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC4] = {"CALL NZ, [0x%04hX]",	&instr_call_nz_a16,	2,	12, 24},
    [0xCC] = {"CALL Z, [0x%04hX]",	&instr_call_z_a16,	2,	12, 24},
    [0xD4] = {"CALL NC, [0x%04hX]",	&instr_call_nc_a16,	2,	12, 24},
    [0xDC] = {"CALL C, [0x%04hX]",	&instr_call_c_a16,	2,	12, 24},

    /*
    **                               RESTARTS
    ** ________________________________________________________________________
    */

    // RST n : push present address onto stack. Jump to address $0000 + n.
    [0xC7] = {"RST 0x00",		&instr_rst_00,		0,	16, 0},
    [0xCF] = {"RST 0x08",		&instr_rst_08,		0,	16, 0},
    [0xD7] = {"RST 0x10",		&instr_rst_10,		0,	16, 0},
    [0xDF] = {"RST 0x18",		&instr_rst_18,		0,	16, 0},
    [0xE7] = {"RST 0x20",		&instr_rst_20,		0,	16, 0},
    [0xEF] = {"RST 0x28",		&instr_rst_28,		0,	16, 0},
    [0xF7] = {"RST 0x30",		&instr_rst_30,		0,	16, 0},
    [0xFF] = {"RST 0x38",		&instr_rst_38,		0,	16, 0},

    /*
    **                               RETURNS
    ** ________________________________________________________________________
    */

    // RET : pop two bytes from stack and jump to that address.
    [0xC9] = {"RET",			&instr_ret,		0,	8, 0},

    // RET cond : return if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC0] = {"RET NZ",			&instr_ret_nz,		0,	8, 20},
    [0xC8] = {"RET Z",			&instr_ret_z,		0,	8, 20},
    [0xD0] = {"RET NC",			&instr_ret_nc,		0,	8, 20},
    [0xD8] = {"RET C",			&instr_ret_c,		0,	8, 20},

    // RETI : pop two bytes from stack & jump
    // to that address then enable interrupts.
    [0xD9] = {"RETI",			&instr_reti,		0,	8, 0},

    // PREFIX CB
    [0xCB] = {"PREFIX CB",		&instr_prefix_cb,	1,	4, 0},

};
