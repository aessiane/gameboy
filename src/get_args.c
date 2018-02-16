#include "gameboy.h"
#include "get_args.h"
#include "errors.h"

int		get_args(int argc, char **argv, t_gameboy *gb)
{
  if (argc != NB_ARGS)
    return (perr(USAGE, argv[0]));
  gb->file.name = argv[1];
  gb->gpu.display.scale = 4;
  return (0);
}
