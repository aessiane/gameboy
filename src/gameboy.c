#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <unistd.h>
#include "memory_rw.h"
#include "gameboy.h"
#include "timing.h"
#include "timer.h"
#include "rom.h"
#include "gpu.h"
#include "cpu.h"
#include "infos.h"
#include "joypad.h"

int		init_gameboy(t_gameboy *gb)
{
  if (load_rom(gb) || init_memory(gb))
    return (1);
  init_registers(gb);
  init_hardware_registers(gb);
  gb->interrupts.master = true;
  gb->interrupts.state = ENABLED;
  return (0);
}

int		run_gameboy(t_gameboy *gb)
{
  struct timespec res = {0, 0};

  clock_gettime(CLOCK_MONOTONIC_RAW, &res);
  gb->timing.last = res.tv_nsec;
  while (!gb->stop)
    {
      /* debug_step done in cpu_step */
      cpu_step(gb);
      interrupts_step(gb);
      joypad_step(gb);
      gpu_step(gb);
      timer_step(gb);
      timing(gb);
    }
  return (0);
}
