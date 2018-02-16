#ifndef INFOS_H_
# define INFOS_H_

typedef struct s_header		t_header;
typedef struct s_gameboy	t_gameboy;

void		print_header_infos(t_header *header);
void		print_instruction_infos(t_gameboy *gb, unsigned char opcode);
void		print_registers(t_gameboy *gb);

#endif /* !INFOS_H_ */
