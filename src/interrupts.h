#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

# include <stdbool.h>

#define ask_interrupt(interrupt_name, value)				\
static inline void ask_##interrupt_name##_interrupt(uint8_t *_if)		\
{									\
*_if |= (1 << value);							\
}

ask_interrupt(vblank, 0)
ask_interrupt(lcd_stat, 1)
ask_interrupt(timer, 2)
ask_interrupt(serial, 3)
ask_interrupt(joypad, 4)

enum			e_interrupts_state {
    ENABLED		= (1 << 1),
    DISABLED		= (1 << 2),
    ENABLE_NEXT		= (1 << 3),
    DISABLE_NEXT	= (1 << 4),
};

typedef struct			s_interrupts
{
  bool				master;
  enum e_interrupts_state	state;
}				t_interrupts;

void		interrupts_step(t_gameboy *gb);

#endif /* !INTERRUPTS_H_ */
