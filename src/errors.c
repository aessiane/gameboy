#include <stdio.h>
#include <stdarg.h>

int		perr(char const *format, ...)
{
  va_list	ap;

  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  return (1);
}
