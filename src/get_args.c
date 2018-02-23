#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include "gameboy.h"
#include "get_args.h"
#include "errors.h"

int       get_args(int argc, char **argv, t_gameboy *gb)
{
  int     opt;
  char    *endptr;

  while ((opt = getopt(argc, argv, ARG_STR)) != -1) {
      switch (opt) {
        case DEBUG_ARG: {
            gb->debug.enabled = true;
            break;
        }
        case SCALE_ARG: {
            errno = 0;
            gb->gpu.display.scale = strtoul(optarg, &endptr, 0);
            if (errno || *optarg == '\0' || *endptr != '\0') {
                perr(SCALE_CONVERSION_ERROR, optarg, argv[0]);
                return (1);
            }
            break;
        }
        case HELP_ARG: {
            printf(LONG_USAGE, argv[0]);
            return (1);
        }
        default: /* ? */ {
            perr(SHORT_USAGE, argv[0], argv[0]);
            return (1);
        }
      }
  }
  if (argv[optind] == NULL) {
      perr(FILENAME_EXPECTED_ERROR, argv[0]);
      return (1);
  }
  gb->file.name = argv[optind];
  return (0);
}
