#ifndef REGISTERS_H_
# define REGISTERS_H_

# include <stdbool.h>
# include <stdint.h>
# include "memory.h"

# define IS_NEG(a) (a >> ((sizeof(a) * 8) - 1))
# define IS_POS(a) ((~a) >> ((sizeof(a) * 8) - 1))

typedef struct          s_registers
{
  struct {
      union {
          struct {
# ifdef L_ENDIAN
              uint8_t   f;
              uint8_t   a;
# else
              uint8_t   a;
              uint8_t   f;
# endif /* !L_ENDIAN */
          };
          uint16_t      af;
      };
  };

  struct {
      union {
          struct {
# ifdef L_ENDIAN
              uint8_t   c;
              uint8_t   b;
# else
              uint8_t   b;
              uint8_t   c;
#endif /* !L_ENDIAN */
          };
          uint16_t      bc;
      };
  };

  struct {
      union {
          struct {
# ifdef L_ENDIAN
              uint8_t   e;
              uint8_t   d;
# else
              uint8_t   d;
              uint8_t   e;
# endif /* !L_ENDIAN */
          };
          uint16_t      de;
      };
  };

  struct {
      union {
          struct {
# ifdef L_ENDIAN
              uint8_t   l;
              uint8_t   h;
# else
              uint8_t   h;
              uint8_t   l;
# endif /* !L_ENDIAN */
          };
          uint16_t      hl;
      };
  };

  uint16_t              sp;
  uint16_t              pc;
}                       t_registers;

typedef struct  s_hardware_registers
{
  uint8_t       *p1;
  uint8_t       *sb;
  uint8_t       *sc;
  uint8_t       *div;
  uint8_t       *tima;
  uint8_t       *tma;
  uint8_t       *tac;
  uint8_t       *_if;
  uint8_t       *nr10;
  uint8_t       *nr11;
  uint8_t       *nr12;
  uint8_t       *nr13;
  uint8_t       *nr14;
  uint8_t       *nr21;
  uint8_t       *nr22;
  uint8_t       *nr23;
  uint8_t       *nr24;
  uint8_t       *nr30;
  uint8_t       *nr31;
  uint8_t       *nr32;
  uint8_t       *nr33;
  uint8_t       *nr34;
  uint8_t       *nr41;
  uint8_t       *nr42;
  uint8_t       *nr43;
  uint8_t       *nr44;
  uint8_t       *nr50;
  uint8_t       *nr51;
  uint8_t       *nr52;
  uint8_t       *wpr;
  uint8_t       *lcdc;
  uint8_t       *stat;
  uint8_t       *scy;
  uint8_t       *scx;
  uint8_t       *ly;
  uint8_t       *lyc;
  uint8_t       *dma;
  uint8_t       *bgp;
  uint8_t       *obp0;
  uint8_t       *obp1;
  uint8_t       *wy;
  uint8_t       *wx;
  uint8_t       *ie;
}               t_hardware_registers;

enum                    e_flags
{
  CARRY_FLAG = 4,
  HALF_CARRY_FLAG,
  SUBSTRACT_FLAG,
  ZERO_FLAG
};

/*
 ** 'set' and 'unset' flag can be replaced by :
 ** registers->f ^= (-bit ^ registers->f) & (1 << value);
 */

# define flag_attr(flag_name, value)                                        \
  static inline void attr_##flag_name(t_registers *registers, bool bit)     \
{                                                                           \
  registers->f ^= (-bit ^ registers->f) & (1 << value);                     \
}


# define flag_setter(flag_name, value)                               \
  static inline void set_##flag_name(t_registers *registers)         \
{                                                                    \
  registers->f |= (1 << value);                                      \
}

# define flag_unsetter(flag_name, value)                             \
  static inline void unset_##flag_name(t_registers *registers)       \
{                                                                    \
  registers->f &= ~(1 << value);                                     \
}

# define flag_getter(flag_name, value)                       \
  static inline bool get_##flag_name(uint8_t flags)          \
{                                                            \
  return ((flags & (1 << value)) >> value);                  \
}

flag_attr(carry_flag, CARRY_FLAG)
flag_attr(half_carry_flag, HALF_CARRY_FLAG)
flag_attr(substract_flag, SUBSTRACT_FLAG)
flag_attr(zero_flag, ZERO_FLAG)

flag_setter(carry_flag, CARRY_FLAG)
flag_setter(half_carry_flag, HALF_CARRY_FLAG)
flag_setter(substract_flag, SUBSTRACT_FLAG)
flag_setter(zero_flag, ZERO_FLAG)

flag_unsetter(carry_flag, CARRY_FLAG)
flag_unsetter(half_carry_flag, HALF_CARRY_FLAG)
flag_unsetter(substract_flag, SUBSTRACT_FLAG)
flag_unsetter(zero_flag, ZERO_FLAG)

flag_getter(carry_flag, CARRY_FLAG)
flag_getter(half_carry_flag, HALF_CARRY_FLAG)
flag_getter(substract_flag, SUBSTRACT_FLAG)
flag_getter(zero_flag, ZERO_FLAG)

void init_hardware_registers(t_gameboy *gb);
void init_registers(t_gameboy *gb);

void set_if_zero(t_registers *registers, uint8_t value);
void set_if_carry(t_registers *registers, uint8_t a, uint8_t b, uint8_t res);
void set_if_half_carry(t_registers *registers, uint8_t a, uint8_t b);

void set_if_no_borrow_carry(t_registers *registers, uint8_t a, uint8_t b);
void set_if_no_borrow_half_carry(t_registers *registers, uint8_t a, uint8_t b);

void set_if_carry_bit15(t_registers *registers, uint16_t a, uint16_t b, uint16_t res);

void set_if_half_carry_bit11(t_registers *registers, uint16_t a, uint16_t b);

#endif /* !REGISTERS_H_ */
