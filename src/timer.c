#include "gameboy.h"
#include "timer.h"
#include "interrupts.h"

void            div_timer(t_gameboy *gb)
{
  gb->timer.div_counter += gb->instruction.cycles;
  if (gb->timer.div_counter > DIV_INC_FREQUENCY) {
      gb->timer.div_counter -= DIV_INC_FREQUENCY;
      *gb->hregisters.div = (*gb->hregisters.div == 0xFF ?
                             0 : *gb->hregisters.div + 1);
  }
}

void            timer_step(t_gameboy *gb)
{
  static unsigned const timings[] = { 4096, 262144, 65536, 16384 };
  uint8_t const tac = *gb->hregisters.tac;

  div_timer(gb);

  if (!(tac & TC_TIMER_STOP))
    return ;

  unsigned clock_select = timings[tac & TC_CLOCK_SELECT];

  gb->timer.timer_counter += gb->instruction.cycles;

  if (gb->timer.timer_counter >= clock_select) {
      gb->timer.timer_counter -= clock_select;
      if (*gb->hregisters.tima == 0xFF) {
          *gb->hregisters.tima = *gb->hregisters.tma;
          ask_timer_interrupt(gb->hregisters._if);
      }
      else {
          *gb->hregisters.tima += 1;
      }
  }
}
