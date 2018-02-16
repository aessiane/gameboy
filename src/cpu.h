#ifndef CPU_H_
#define CPU_H_

# define GB_CPU_FREQUENCY 4194304

typedef struct s_gameboy	t_gameboy;

typedef struct	s_fetched
{
  unsigned char	opcode;
  union {
      char	op_len8;
      short	op_len16;
  };
  unsigned char	cycles;
}		t_fetched;

void		cpu_step(t_gameboy *gb);

#endif /* !CPU_H_ */
