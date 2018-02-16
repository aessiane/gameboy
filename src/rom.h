#ifndef ROM_H_
# define ROM_H_

# define MIN_ROM_SIZE	0x8000

typedef struct s_gameboy	t_gameboy;

typedef struct		s_header
{
  char			*start;
  char			nintendo[0x30];
  union
    {
      struct
	{
	  char			unused2[11];
	  char			manufacturer_code[4];
	  char			cbg_flag;
	};
      char			title[16];
    };
  short			new_licensee_code;
  unsigned char		sgb_flag;
  unsigned char		cart_type;
  unsigned char		cart_rom_size;
  unsigned char		cart_ram_size;
  unsigned char		destination_code;
  unsigned char		old_licensee_code;
  unsigned char		mask_rom_version;
  unsigned char		header_checksum;
  short			global_checksum;
}			t_header;

enum			e_cartbridge_type
{
  CT_ROM_ONLY
};

typedef struct		s_rom
{
  char			*start;
  t_header		header;
}			t_rom;

typedef struct		s_assoc_array
{
  unsigned		key;
  char const		*value;
}			t_assoc_array;

int		load_rom(t_gameboy *gb);

# define NB_CB_TYPES		31
# define NB_ROM_SIZES		11
# define NB_RAM_SIZES		6

extern t_assoc_array const	g_cb_types[NB_CB_TYPES];
extern t_assoc_array const	g_rom_sizes[NB_ROM_SIZES];
extern t_assoc_array const	g_ram_sizes[NB_RAM_SIZES];

#endif /* !ROM_H_ */
