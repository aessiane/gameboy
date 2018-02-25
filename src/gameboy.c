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

int run_gameboy(t_gameboy *gb)
{
  while (!gb->stop) {
      /* debug_step is done in cpu_step */
      /* the joypad_step is done in gpu_step */
      cpu_step(gb);
      gb->timing.cycles_count += gb->instruction.cycles;
      interrupts_step(gb);
      gpu_step(gb);
      timer_step(gb);
  }
  return (0);
}

int init_gameboy(t_gameboy *gb)
{
  if (load_rom(gb) || init_memory(gb)) {
      return (1);
  }
  init_registers(gb);
  init_hardware_registers(gb);
  gb->interrupts.master = true;
  gb->interrupts.state = ENABLED;
  return (0);
}
