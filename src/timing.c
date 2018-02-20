#define _POSIX_C_SOURCE 199309L
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "gameboy.h"
#include "timing.h"
#include "cpu.h"

void	init_timing(t_gameboy *gb)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, &gb->timing.last);
  gb->timing.cycles_count = 0;
}

/*
** Should be called each time the screen is refreshed
*/
void	timing(t_gameboy *gb)
{
  struct timespec res = {0, 0};

  clock_gettime(CLOCK_MONOTONIC_RAW, &res);

  /*
  ** The exact formula should be
  ** (gb->timing.cycles_count / GB_CPU_FREQUENCY) * 1E6
  ** but I first do the multiplication to avoid casting to double for
  ** the division
  */
  uint32_t usecs_to_wait = (((unsigned long)gb->timing.cycles_count * 1E6L) /
			    GB_CPU_FREQUENCY);
  uint32_t elapsed_usecs = (res.tv_sec - gb->timing.last.tv_sec) * 1E6 +
			    (res.tv_nsec - gb->timing.last.tv_nsec) / 1E3;

  if (usecs_to_wait > elapsed_usecs) {
    usleep(usecs_to_wait - elapsed_usecs);
  }

  clock_gettime(CLOCK_MONOTONIC_RAW, &gb->timing.last);
  gb->timing.cycles_count = 0;
}
