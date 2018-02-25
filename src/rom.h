#ifndef ROM_H_
# define ROM_H_

# define MIN_ROM_SIZE   0x8000

typedef struct s_gameboy        t_gameboy;

typedef struct  s_header
{
  uint8_t       *start;
  char          nintendo[0x30];
  union {
      struct {
          char  unused2[11];
          char  manufacturer_code[4];
          char  cbg_flag;
      };
      char      title[16];
  };
  short         new_licensee_code;
  uint8_t       sgb_flag;
  uint8_t       cart_type;
  uint8_t       cart_rom_size;
  uint8_t       cart_ram_size;
  uint8_t       destination_code;
  uint8_t       old_licensee_code;
  uint8_t       mask_rom_version;
  uint8_t       header_checksum;
  uint16_t      global_checksum;
}               t_header;

enum e_cartbridge_type
{
  CT_ROM_ONLY
};

typedef struct  s_rom
{
  uint8_t       *start;
  t_header      header;
}               t_rom;

typedef struct  s_assoc_array
{
  unsigned      key;
  char const    *value;
}               t_assoc_array;

# define NB_CB_TYPES            31
# define NB_ROM_SIZES           11
# define NB_RAM_SIZES           6

extern t_assoc_array const      g_cb_types[NB_CB_TYPES];
extern t_assoc_array const      g_rom_sizes[NB_ROM_SIZES];
extern t_assoc_array const      g_ram_sizes[NB_RAM_SIZES];

int load_rom(t_gameboy *gb);

#endif /* !ROM_H_ */
