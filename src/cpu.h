#ifndef CPU_H_
# define CPU_H_

# include <stdint.h>

# define GB_CPU_FREQUENCY 4194304

typedef struct s_gameboy        t_gameboy;

typedef struct  s_fetched
{
  uint8_t       opcode;
  union {
      int8_t   op_len8;
      int16_t  op_len16;
  };
  uint8_t       cycles;
}               t_fetched;

void            cpu_step(t_gameboy *gb);

#endif /* !CPU_H_ */
