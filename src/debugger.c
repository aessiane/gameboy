#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "gameboy.h"
#include "utils.h"
#include "memory_rw.h"
#include "debug.h"
#include "infos.h"
#include "errors.h"

#define CONTINUE 1
#define BREAK_SHELL 0

static int	quit_cb(t_gameboy *gb, char **args)
{
  (void)args;
  gb->stop = true;
  return (BREAK_SHELL);
}

static int	infos_cb(t_gameboy *gb, char **args)
{
  (void)args;
  print_registers(gb);
  print_instruction_infos(gb, gb->instruction.opcode);
  return (CONTINUE);
}

static int	sf_cb(t_gameboy *gb, char **args)
{
  int		depth;
  char		*endptr = NULL;

  if (word_tab_len((char const **)args) != 0) {
      errno = 0;
      depth = strtol(args[0], &endptr, 10);
      if (endptr[0] != '\0' || errno) {
	  depth = DEFAULT_STACK_DUMPING;
      }
  }
  else {
      depth = DEFAULT_STACK_DUMPING;
  }
  for (int i = 0; i < (depth * 2); i += 2) {
      uint16_t const address = gb->registers.sp + i;

      printf("%#04x:\t|%04x|\n", address, fetch_word(gb, address));
      if (address == 0xFFFE) {
	  break ;
      }
  }
  return (CONTINUE);
}

static int	break_cb(t_gameboy *gb, char **args)
{
  (void)gb; (void)args;
  return (BREAK_SHELL);
}

static int	delete_cb(t_gameboy *gb, char **args)
{
  (void)gb; (void)args;
  return (CONTINUE);
}

static int	next_cb(t_gameboy *gb, char **args)
{
  (void)gb; (void)args;
  return (BREAK_SHELL);
}

static int	continue_cb(t_gameboy *gb, char **args)
{
  (void)args;
  gb->debug.enabled = false;
  return (BREAK_SHELL);
}

static int	print_cb(t_gameboy *gb, char **args)
{
  int		address;
  int		nol = DEFAULT_PRINT_LINES;
  char		*endptr =  NULL;

  if (word_tab_len((char const **)args) == 0) {
      perr("Usage: print address [number_of_lines]\n");
      return (CONTINUE);
  }
  errno = 0;
  address = strtol(args[0], &endptr, 0);
  if (endptr[0] != '\0' || errno) {
      perr("Error while parsing (%s)\n", args[0]);
      perr("Usage: print address [number_of_lines]\n");
      return (CONTINUE);

  }
  address = address & (~1);
  if (args[1]) {
      errno = 0;
      nol = strtol(args[1], &endptr, 0);
      if (endptr[0] != '\0' || errno)
	nol = DEFAULT_PRINT_LINES;
  }
  for (; nol > 0; --nol) {
      printf("%#04x:\t", address);
      for (int j = 0; j < WORDS_PER_LINE; ++j) {
	  printf("%04x ", fetch_word(gb, address + (j * 2)));
      }
      printf("\n");
      address += (WORDS_PER_LINE * 2);
  }
  return (CONTINUE);
}

static void	free_tab(char **tab)
{
  for (unsigned i = 0; tab[i] != NULL; ++i) {
      free(tab[i]);
  }
}

static int	help_cb(t_gameboy *gb, char **args);

static t_command const	g_commands[] = {
      {"help", "displays all the available commands", 0, &help_cb},
      {"quit", "shutdown the gameboy", 0, &quit_cb},
      {"infos", "displays informations", 0, &infos_cb},
      {"stackframe", "show the n first stack values", 1, &sf_cb},
      {"break", "set a breakpoint", 1, &break_cb},
      /*{"disassemble", "show source code disassembled", 1, &disas_cb},*/
      {"delete", "delete a breakpoint", 1, &delete_cb},
      {"next", "go to next instruction", 0, &next_cb},
      {"continue", "continue the normal execution", 0, &continue_cb},
      {"print", "show a place in memory", 2, &print_cb},
};

static int	help_cb(t_gameboy *gb, char **args)
{
  for (unsigned i = 0; i < sizeof(g_commands) / sizeof(g_commands[0]); ++i) {
      printf("%s: %s\n", g_commands[i].name ,g_commands[i].description);
  }
  (void)gb; (void)args;
  return (CONTINUE);
}

static int	str_to_tab(char **parsing_tab, char const *cmd)
{
  unsigned	i = 0;
  unsigned	parsed = 0;
  unsigned	tab_i = 0;

  do {
      if (isblank(cmd[i]) || cmd[i] == '\n' || cmd[i] == '\0') {
	  if (parsed != 0) {
	      if (tab_i == MAX_DEBUG_ARGS) {
		  perr("Invalid cmd line: Too many arguments.\n");
		  goto parsing_error;
	      }
	      parsing_tab[tab_i] = duplicate_string(cmd + i - parsed, parsed);
	      if (!parsing_tab[tab_i]) {
		  goto parsing_error;
	      }
	      tab_i += 1;
	      parsed = 0;
	  }
      }
      else {
	  parsed += 1;
      }

  } while (cmd[i++] != '\0');
  return (tab_i == 0 ? 1 :0);

parsing_error:
  free_tab(parsing_tab);
  return (CONTINUE);
}

static int	command_line(t_gameboy *gb)
{
  char		cmd[DEBUG_CL_SIZE];
  char		*parsing_tab[MAX_DEBUG_ARGS + 1] = {0};
  int		rd;
  int		ret_value = CONTINUE;

  write(0, gb->debug.prompt, strlen(gb->debug.prompt));
  rd = read(0, cmd, DEBUG_CL_SIZE);
  if (rd == -1) {
      perr("Error while reading: %s\n", strerror(errno));
      return (CONTINUE);
  }
  else if (rd == DEBUG_CL_SIZE) {
      while ((rd = read(0, cmd, DEBUG_CL_SIZE)) == DEBUG_CL_SIZE && rd != -1) ;
      perr("Invalid cmd line: Too many characters.\n");
      return (CONTINUE);
  }
  else if (rd == 0) {
      return (continue_cb(gb, parsing_tab));
  }
  cmd[rd] = '\0';

  if (str_to_tab(parsing_tab, cmd)) {
      return (CONTINUE);
  }
  for (unsigned i = 0; i < sizeof(g_commands) / sizeof(g_commands[0]); ++i) {
      if (!strncmp(g_commands[i].name, parsing_tab[0], strlen(parsing_tab[0]))) {
	  ret_value = (*g_commands[i].func)(gb, parsing_tab + 1);
	  free_tab(parsing_tab);
	  return (ret_value);
      }
  }
  perr("%s is an invalid command; type 'help' for more infos.\n", parsing_tab[0]);
  free_tab(parsing_tab);
  return (ret_value);
}

void		init_debug(t_gameboy *gb)
{
  gb->debug.prompt = "(ege) ";
  gb->debug.enabled = false;
  gb->debug.stop = false;
  gb->debug.breakpoint_mask = 0;
}

void		debug_step(t_gameboy *gb)
{
  if (!gb->debug.enabled) {
      return ;
  }

  print_registers(gb);
  print_instruction_infos(gb, gb->instruction.opcode);

  while (command_line(gb) != 0) {
  }
}
