#ifndef GET_ARGS_H_
# define GET_ARGS_H_

# define NB_ARGS 2

# define ARG_STR   "dhs:"

# define HELP_ARG  'h'
# define DEBUG_ARG 'd'
# define SCALE_ARG 's'

# define SCALE_CONVERSION_ERROR \
  "Error while converting (%s) to an unsigned integer.\n" \
  "Try '%s -h' for more information.\n"

# define FILENAME_EXPECTED_ERROR \
  "No rom file given.\n" \
  "Try '%s -h' for more information.\n"

# define LONG_USAGE \
  "Usage: %s [-d] [-s scale] [-h] rom_file\n"\
  "\n"\
  "  -d                    Enable command-line debug tool;\n"\
  "                        Note that it can be enabled during execution with\n"\
  "                        a CTRL-C.\n"\
  "  -s <scale>            Scales the screen by the given value;\n"\
  "                        The given number must be an integer.\n"\
  "                        (Defaut scaling: 4).\n"\
  "  -h                    Prints the long usage.\n"\

# define SHORT_USAGE \
  "Usage: %s [-d] [-s scale] [-h] rom_file\n"\
  "Try '%s -h' for more information.\n"


int	get_args(int argc, char **argv, t_gameboy *gb);

#endif /* !GET_ARGS_H_ */
