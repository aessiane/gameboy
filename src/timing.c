#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include "gameboy.h"
#include "cpu.h"
#include "timing.h"

void	timing(t_gameboy *gb)
{
  struct timespec res = {0, 0};

  clock_gettime(CLOCK_MONOTONIC_RAW, &res);

  long nsecs_to_wait = ((double)(gb->instruction.cycles) / GB_CPU_FREQUENCY * 1E9);
  long elapsed_nsecs = res.tv_nsec - gb->timing.last;

  do {
      if (gb->timing.last > res.tv_nsec) {
	  gb->timing.last = res.tv_nsec;
      }
      clock_gettime(CLOCK_MONOTONIC_RAW, &res);
      elapsed_nsecs = res.tv_nsec - gb->timing.last;
  } while (nsecs_to_wait > elapsed_nsecs);

  gb->timing.last = res.tv_nsec;
}
