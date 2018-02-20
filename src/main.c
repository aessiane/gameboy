#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infos.h"
#include "gameboy.h"
#include "get_args.h"
#include "debug.h"

#include "memory_rw.h"

static t_gameboy	*g_gb;

void		sighandler(int unused)
{
  (void)unused;

  g_gb->debug.enabled = true;
  signal(SIGINT, &sighandler);
}

int		main(int argc, char *argv[])
{
  t_gameboy	gb;

  g_gb = &gb;
  signal(SIGINT, &sighandler);
  memset(&gb, 0, sizeof(gb));
  init_debug(&gb);
  if (get_args(argc, argv, &gb) || init_gpu(&gb) || init_gameboy(&gb))
    return (EXIT_FAILURE);
  init_timing(&gb);
  run_gameboy(&gb);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
