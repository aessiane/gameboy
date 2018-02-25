#ifndef MEMORY_RW_H_
# define MEMORY_RW_H_

#include <stdint.h>

typedef struct s_memory t_memory;
typedef struct s_gameboy t_gameboy;

uint8_t  fetch_byte(t_gameboy *gb, uint16_t address);
uint16_t fetch_word(t_gameboy *gb, uint16_t address);

void write_byte(t_gameboy *gb, uint16_t address, uint8_t value);
void write_word(t_gameboy *gb, uint16_t address, uint16_t value);

void load_memory(t_memory *memory);

uint8_t   pop_byte(t_gameboy *gb);
uint16_t  pop_word(t_gameboy *gb);
void      push_byte(t_gameboy *gb, uint8_t value);
void      push_word(t_gameboy *gb, uint16_t value);

#endif /* !MEMORY_RW_H_ */
