#ifndef ERRORS_H_
# define ERRORS_H_

# define PROG		"ege"
# define FUNC_ERR(x)	PROG": Error while using `"x"`: %m.\n"

int		perr(char const *, ...);

#endif /* !ERRORS_H_ */
