#include "memory_rw.h"
#include "gameboy.h"

static void		init_hardware_registers_values(t_gameboy *gb)
{
  *gb->hregisters.p1	= 0x3F;
  *gb->hregisters.sb	= 0x00;
  *gb->hregisters.sc	= 0x00;
  *gb->hregisters.div	= 0x00;
  *gb->hregisters.tima	= 0x00;
  *gb->hregisters.tma	= 0x00;
  *gb->hregisters.tac	= 0x00;
  *gb->hregisters._if	= 0x00;
  *gb->hregisters.nr10	= 0x80;
  *gb->hregisters.nr11	= 0xBF;
  *gb->hregisters.nr12	= 0xF3;
  *gb->hregisters.nr13	= 0x00;
  *gb->hregisters.nr14	= 0xBF;
  *gb->hregisters.nr21	= 0x3F;
  *gb->hregisters.nr22	= 0x00;
  *gb->hregisters.nr23	= 0x00;
  *gb->hregisters.nr24	= 0xBF;
  *gb->hregisters.nr30	= 0x7F;
  *gb->hregisters.nr31	= 0xFF;
  *gb->hregisters.nr32	= 0x9F;
  *gb->hregisters.nr33	= 0xBF;
  *gb->hregisters.nr34	= 0x00;
  *gb->hregisters.nr41	= 0xFF;
  *gb->hregisters.nr42	= 0x00;
  *gb->hregisters.nr43	= 0x00;
  *gb->hregisters.nr44	= 0xBF;
  *gb->hregisters.nr50	= 0x77;
  *gb->hregisters.nr51	= 0xF3;
  *gb->hregisters.nr52	= 0x91;
  *gb->hregisters.wpr	= 0x00;
  *gb->hregisters.lcdc	= 0x00;
  *gb->hregisters.stat	= 0x00;
  *gb->hregisters.scy	= 0x00;
  *gb->hregisters.scx	= 0x00;
  *gb->hregisters.ly	= 0x00;
  *gb->hregisters.lyc	= 0x00;
  *gb->hregisters.dma	= 0x00;
  *gb->hregisters.bgp	= 0xFC;
  *gb->hregisters.obp0	= 0xFF;
  *gb->hregisters.obp1	= 0xFF;
  *gb->hregisters.wy	= 0x00;
  *gb->hregisters.wx	= 0x00;
  *gb->hregisters.ie	= 0x00;
}

static void		init_hardware_addresses(t_gameboy *gb)
{
  gb->hregisters.p1	= gb->memory.start + 0xFF00;
  gb->hregisters.sb	= gb->memory.start + 0xFF01;
  gb->hregisters.sc	= gb->memory.start + 0xFF02;
  gb->hregisters.div	= gb->memory.start + 0xFF04;
  gb->hregisters.tima	= gb->memory.start + 0xFF05;
  gb->hregisters.tma	= gb->memory.start + 0xFF06;
  gb->hregisters.tac	= gb->memory.start + 0xFF07;
  gb->hregisters._if	= gb->memory.start + 0xFF0F;
  gb->hregisters.nr10	= gb->memory.start + 0xFF10;
  gb->hregisters.nr11	= gb->memory.start + 0xFF11;
  gb->hregisters.nr12	= gb->memory.start + 0xFF12;
  gb->hregisters.nr13	= gb->memory.start + 0xFF13;
  gb->hregisters.nr14	= gb->memory.start + 0xFF14;
  gb->hregisters.nr21	= gb->memory.start + 0xFF16;
  gb->hregisters.nr22	= gb->memory.start + 0xFF17;
  gb->hregisters.nr23	= gb->memory.start + 0xFF18;
  gb->hregisters.nr24	= gb->memory.start + 0xFF19;
  gb->hregisters.nr30	= gb->memory.start + 0xFF1A;
  gb->hregisters.nr31	= gb->memory.start + 0xFF1B;
  gb->hregisters.nr32	= gb->memory.start + 0xFF1C;
  gb->hregisters.nr33	= gb->memory.start + 0xFF1D;
  gb->hregisters.nr34	= gb->memory.start + 0xFF1E;
  gb->hregisters.nr41	= gb->memory.start + 0xFF20;
  gb->hregisters.nr42	= gb->memory.start + 0xFF21;
  gb->hregisters.nr43	= gb->memory.start + 0xFF22;
  gb->hregisters.nr44	= gb->memory.start + 0xFF23;
  gb->hregisters.nr50	= gb->memory.start + 0xFF24;
  gb->hregisters.nr51	= gb->memory.start + 0xFF25;
  gb->hregisters.nr52	= gb->memory.start + 0xFF26;
  gb->hregisters.wpr	= gb->memory.start + 0xFF30;
  gb->hregisters.lcdc	= gb->memory.start + 0xFF40;
  gb->hregisters.stat	= gb->memory.start + 0xFF41;
  gb->hregisters.scy	= gb->memory.start + 0xFF42;
  gb->hregisters.scx	= gb->memory.start + 0xFF43;
  gb->hregisters.ly	= gb->memory.start + 0xFF44;
  gb->hregisters.lyc	= gb->memory.start + 0xFF45;
  gb->hregisters.dma	= gb->memory.start + 0xFF46;
  gb->hregisters.bgp	= gb->memory.start + 0xFF47;
  gb->hregisters.obp0	= gb->memory.start + 0xFF48;
  gb->hregisters.obp1	= gb->memory.start + 0xFF49;
  gb->hregisters.wy	= gb->memory.start + 0xFF4A;
  gb->hregisters.wx	= gb->memory.start + 0xFF4B;
  gb->hregisters.ie	= gb->memory.start + 0xFFFF;
}

void			init_hardware_registers(t_gameboy *gb)
{
  init_hardware_addresses(gb);
  init_hardware_registers_values(gb);
}

void			init_registers(t_gameboy *gb)
{
  gb->registers.af	= 0x01B0;
  gb->registers.bc	= 0x0013;
  gb->registers.de	= 0x00D8;
  gb->registers.hl	= 0x014D;
  gb->registers.sp	= 0xFFFE;
  gb->registers.pc	= 0x0100;
}

void			set_if_carry(t_registers *registers, unsigned char a, unsigned char b, unsigned char res)
{
  if ((IS_NEG(a) & IS_NEG(b)) | (IS_NEG(a) & IS_POS(res)) | (IS_NEG(b) & IS_POS(res)))
    set_carry_flag(registers);
  else
    unset_carry_flag(registers);
}

void			set_if_zero(t_registers *registers, unsigned char value)
{
  if (value)
    unset_zero_flag(registers);
  else
    set_zero_flag(registers);
}

void			set_if_half_carry(t_registers *registers, unsigned char a, unsigned char b)
{
  if (((a & 0xF) + (b & 0xF)) & 0x10)
    set_half_carry_flag(registers);
  else
    unset_half_carry_flag(registers);
}

void			set_if_no_borrow_carry(t_registers *registers, unsigned char a, unsigned char b)
{
  if (a < b)
    set_carry_flag(registers);
  else
    unset_carry_flag(registers);
}

void			set_if_no_borrow_half_carry(t_registers *registers, unsigned char a, unsigned char b)
{
  if ((((char)a & 0x0F) - ((char)b & 0x0F)) > 0)
    set_half_carry_flag(registers);
  else
    unset_half_carry_flag(registers);
}

void			set_if_half_carry_bit11(t_registers *registers, unsigned short a, unsigned short b)
{
  if (((a & 0xFFF) + (b & 0xFFF)) & 0x1000)
    set_half_carry_flag(registers);
  else
    unset_half_carry_flag(registers);
}

void			set_if_carry_bit15(t_registers *registers, unsigned short a, unsigned short b, unsigned short res)
{
  if ((IS_NEG(a) & IS_NEG(b)) | (IS_NEG(a) & IS_POS(res)) | (IS_NEG(b) & IS_POS(res)))
    set_carry_flag(registers);
  else
    unset_carry_flag(registers);
}

