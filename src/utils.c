#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "errors.h"

void            dump_word_tab(char const * const *wordtab)
{
  for (unsigned i = 0; wordtab[i] != NULL; ++i) {
      printf("[%i] = %s\n", i, wordtab[i]);
  }
}

unsigned        word_tab_len(char const * const *wordtab)
{
  unsigned i = 0;

  for (i = 0; wordtab[i] != NULL; ++i) ;
  return (i);
}

char            *duplicate_string(char const *str, int n)
{
  char          *dup;
  unsigned      to_copy = (n == -1 ? strlen(str) : (unsigned)n);

  dup = malloc(to_copy + 1);
  if (dup != NULL) {
      strncpy(dup, str, to_copy);
      dup[to_copy] = '\0';
  }
  return (dup);
}

long            fsize(FILE *fs)
{
  long          size;

  fseek(fs, 0, SEEK_END);
  size = ftell(fs);
  fseek(fs, 0, SEEK_SET);
  return (size);
}

int             check_file_type(char const *name)
{
#ifdef WIN32
# define IS_REGULAR_FILE(x)     ((x) & _S_IFREG)
  struct _stat  buffer;

  if (_stat(name, &buffer) == -1)
#else
# define IS_REGULAR_FILE(x)     (S_ISREG(x))
    struct stat buffer;

  if (stat(name, &buffer) == -1)
#endif /* !WIN32 */
    {
      perr("Can't load the cartbridge `%s` : %m.\n", name);
      return (-1);
    }
  if (IS_REGULAR_FILE(buffer.st_mode))
    return (buffer.st_size);
  perr("The cartbridge must be a regular file.\n", name);
  return (-1);
}
