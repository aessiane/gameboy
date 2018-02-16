#ifndef TIMING_H_
# define TIMING_H_

#include <time.h>

typedef struct s_gameboy	t_gameboy;

typedef struct s_timing
{
  long		last;
}		t_timing;

void timing(t_gameboy *gb);

#endif /* !TIMING_H_ */
