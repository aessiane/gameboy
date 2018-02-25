#ifndef DEBUG_H_
# define DEBUG_H_

# include <stdbool.h>

# define DEBUG_CL_SIZE          50
# define MAX_DEBUG_ARGS         3
# define MAX_NB_BREAKPOINT      4
# define DEFAULT_STACK_DUMPING  10

# define DEFAULT_PRINT_LINES    4
# define WORDS_PER_LINE         4

typedef struct  s_command
{
  char const    *name;
  char const    *description;
  unsigned      nb_args;
  int           (*func)(t_gameboy *, char **);
}               t_command;

typedef struct  s_debug
{
  char          *prompt;
  unsigned      breakpoint[MAX_NB_BREAKPOINT];
  unsigned      breakpoint_mask;
  bool          enabled;
  bool          stop;
}               t_debug;

void            debug_step(t_gameboy *gb);
void            init_debug(t_gameboy *gb);

#endif /* !DEBUG_H_ */
