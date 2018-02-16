#ifndef TIMER_H_
# define TIMER_H_

# define DIV_INC_FREQUENCY 16384

typedef struct s_gameboy	t_gameboy;

enum e_timercontrol
{
  TC_TIMER_STOP = (1 << 2),
  TC_CLOCK_SELECT = (1 << 0) | (1 << 1)
};

typedef struct	s_timer
{
  unsigned	timer_counter;
  unsigned	div_counter;
}		t_timer;

void		timer_step(t_gameboy *gb);

#endif /* !TIMER_H_ */
