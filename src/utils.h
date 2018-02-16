#ifndef UTILS_H_
# define UTILS_H_

# include <stdio.h>

void		dump_word_tab(char const **wordtab);
unsigned	word_tab_len(char const **wordtab);
char		*duplicate_string(char const *str, int n);
long		fsize(FILE *fs);
int		check_file_type(char const *name);

#endif /* !UTILS_H_ */
