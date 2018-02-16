#ifndef MEMORY_RW_H_
# define MEMORY_RW_H_

typedef struct s_memory		t_memory;
typedef struct s_gameboy	t_gameboy;

char		fetch_byte(t_gameboy *gb, unsigned short address);
unsigned short	fetch_word(t_gameboy *gb, unsigned short address);

void		write_byte(t_gameboy *gb, unsigned short address, unsigned char value);
void		write_word(t_gameboy *gb, unsigned short address, unsigned short value);

void		load_memory(t_memory *memory);

unsigned char	pop_byte(t_gameboy *gb);
unsigned short	pop_word(t_gameboy *gb);
void		push_byte(t_gameboy *gb, unsigned char value);
void		push_word(t_gameboy *gb, unsigned short value);

#endif /* !MEMORY_RW_H_ */
