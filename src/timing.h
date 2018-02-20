#ifndef TIMING_H_
# define TIMING_H_

#include <time.h>

typedef struct s_gameboy	t_gameboy;

typedef struct s_timing
{
  struct timespec	last;
  uint32_t		cycles_count;
}		t_timing;

void timing(t_gameboy *gb);
void	init_timing(t_gameboy *gb);

#endif /* !TIMING_H_ */
