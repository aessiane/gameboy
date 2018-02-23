#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infos.h"
#include "gameboy.h"
#include "gpu.h"
#include "get_args.h"
#include "debug.h"

#include "memory_rw.h"

static t_gameboy	*g_gb;

/*
** Use CTRL-C to start the debugger
*/
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

  /*
  ** First call the initializers to set the default values,
  ** then call the argument parser to modify them if needed.
  */
  memset(&gb, 0, sizeof(gb));
  init_debug(&gb);
  init_timing(&gb);
  init_gpu(&gb);
  if (get_args(argc, argv, &gb) || init_gameboy(&gb) || start_gpu(&gb))
    return (EXIT_FAILURE);
  run_gameboy(&gb);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
