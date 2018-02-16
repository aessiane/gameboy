#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "gameboy.h"
#include "memory_rw.h"
#include "rom.h"
#include "utils.h"
#include "infos.h"

t_assoc_array const	g_cb_types[NB_CB_TYPES] = {
      {0x00, "ROM ONLY"},
      {0x01, "MBC1"},
      {0x02, "MBC1+RAM"},
      {0x03, "MBC1+RAM+BATTERY"},
      {0x05, "MBC2"},
      {0x06, "MBC2+BATTERY"},
      {0x08, "ROM+RAM"},
      {0x09, "ROM+RAM+BATTERY"},
      {0x0B, "MMM01"},
      {0x0C, "MMM01+RAM"},
      {0x0D, "MMM01+RAM+BATTERY"},
      {0x0F, "MBC3+TIMER+BATTERY"},
      {0x10, "MBC3+TIMER+RAM+BATTERY"},
      {0x11, "MBC3"},
      {0x12, "MBC3+RAM"},
      {0x13, "MBC3+RAM+BATTERY"},
      {0x15, "MBC4"},
      {0x16, "MBC4+RAM"},
      {0x17, "MBC4+RAM+BATTERY"},
      {0x19, "MBC5"},
      {0x1A, "MBC5+RAM"},
      {0x1B, "MBC5+RAM+BATTERY"},
      {0x1C, "MBC5+RUMBLE"},
      {0x1D, "MBC5+RUMBLE+RAM"},
      {0x1E, "MBC5+RUMBLE+RAM+BATTERY"},
      {0x20, "MBC6"},
      {0x22, "MBC7+SENSOR+RUMBLE+RAM+BATTERY"},
      {0xFC, "POCKET CAMERA"},
      {0xFD, "BANDAI TAMA5"},
      {0xFE, "HuC3"},
      {0xFF, "HuC1+RAM+BATTERY"},
};

t_assoc_array const	g_rom_sizes[NB_ROM_SIZES] = {
      {0x00, "32KByte (no ROM banking)"},
      {0x01, "64KByte (4 banks)"},
      {0x02, "128KByte (8 banks)"},
      {0x03, "256KByte (16 banks)"},
      {0x04, "512KByte (32 banks)"},
      {0x05, "1MByte (64 banks)"},
      {0x06, "2MByte (128 banks)"},
      {0x07, "4MByte (256 banks)"},
      {0x52, "1.1MByte (72 banks)"},
      {0x53, "1.2MByte (80 banks)"},
      {0x54, "1.5MByte (96 banks)"},
};

t_assoc_array const	g_ram_sizes[NB_RAM_SIZES] = {
      {0x00, "None"},
      {0x01, "2 KBytes"},
      {0x02, "8 Kbytes"},
      {0x03, "32 KBytes (4 banks of 8KBytes each)"},
      {0x04, "128 KBytes (16 banks of 8KBytes each)"},
      {0x05, "64 KBytes (8 banks of 8KBytes each)"},
};

static FILE	*check_and_open_file(t_gameboy *gb)
{
  FILE		*fs;

  if ((gb->file.size = check_file_type(gb->file.name)) == -1)
    return (NULL);
  else if (gb->file.size < MIN_ROM_SIZE)
    {
      perr("Invalid rom: file too short !\n");
      return (NULL);
    }
  else if ((fs = fopen(gb->file.name, "r")) == NULL)
    {
      perr(FUNC_ERR("fopen"));
      return (NULL);
    }
  return (fs);
}

static int	dump_rom(t_gameboy *gb, FILE *fs)
{
  long		size;
  long		pos = 0;
  long		readed;

  if ((gb->rom.start = malloc(gb->file.size)) == NULL)
    return (perr(FUNC_ERR("malloc")));
  size = gb->file.size;
  while (size && !feof(fs) && !ferror(fs))
    {
      readed = fread(gb->rom.start + pos, size, 1, fs);
      pos += readed;
      size -= readed;
    }
  return (ferror(fs) ? perr(FUNC_ERR("fread")) : 0);
}

static unsigned short	get_word(void *const address)
{
#ifdef L_ENDIAN
  return ((*((unsigned short *)address) & 0x00FF) << 8) |
    ((*((unsigned short *)address) & 0xFF00) >> 8);
#else
  return (*((unsigned short *)address));
# endif /* !L_ENDIAN */
}

/*
** I could have read the whole structure by packing it,
** but for eventual portability problems, I decided to fill it
** field by field
*/
static void	get_rom_header(t_gameboy *gb)
{
  t_header	*header = &gb->rom.header;

  header->start = gb->rom.start + 0x100;
  memcpy(header->nintendo, header->start + 0x04, sizeof(header->nintendo));
  memcpy(header->title, header->start + 0x34, sizeof(header->title));
  header->new_licensee_code = get_word(header->start + 0x44);
  header->sgb_flag = header->start[0x46];
  header->cart_type = header->start[0x47];
  header->cart_rom_size = header->start[0x48];
  header->cart_ram_size = header->start[0x49];
  header->destination_code = header->start[0x4A];
  header->old_licensee_code = header->start[0x4B];
  header->mask_rom_version = header->start[0x4C];
  header->header_checksum = header->start[0x4D];
  header->global_checksum = get_word(header->start + 0x4E);
  print_header_infos(&gb->rom.header);
}

static int	check_header_checksum(t_gameboy *gb)
{
  unsigned char	checksum = 0;

/*#warning "Remove this"*/
  /*return (0);*/
  printf("Rom checksum : %d\n", gb->rom.header.header_checksum);
  for (unsigned i = 0x34; i <= 0x4C; ++i)
    {
      checksum = checksum - (gb->rom.header.start[i]) - 1;
    }
  printf("Obtained checksum : %d\n", checksum);
  return (gb->rom.header.header_checksum != checksum ?
	  perr("The header checksum is invalid !\n") : 0);
  printf("_________________________\n\n");
}

static int	check_ram_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_ram_sizes) / sizeof(g_ram_sizes)); ++i)
    {
      if (g_ram_sizes[i].key == rs)
	return (0);
    }
  return (perr("Invalid ram size byte!\n"));
}

static int	check_rom_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_rom_sizes) / sizeof(g_rom_sizes)); ++i)
    {
      if (g_rom_sizes[i].key == rs)
	return (0);
    }
  return (perr("Invalid rom size byte!\n"));
}

static int	check_cartbridge_type(unsigned char ct)
{
  if (ct != CT_ROM_ONLY)
    return (perr("Only the ROM only cartbridges are supported !\n"));
  return (0);
  // The 3 lines above must be removed after the MBC's implementation.
  for (unsigned i = 0; i < (sizeof(g_cb_types) / sizeof(g_cb_types[0])); ++i)
    {
      if (g_cb_types[i].key == ct)
	return (0);
    }
  return (perr("Invalid cartbridge type byte !\n"));
}

static int	check_rom_header(t_gameboy *gb)
{
  t_header	*header = &gb->rom.header;

  if (header->sgb_flag == 3)
    return (perr("SGB not supported !\n"));
  else if (check_header_checksum(gb) ||
	   check_cartbridge_type(header->cart_type) ||
	   check_rom_size(header->cart_rom_size) ||
	   check_ram_size(header->cart_ram_size))
    return (1);
  return (0);
}

int		load_rom(t_gameboy *gb)
{
  FILE		*fs;

  if ((fs = check_and_open_file(gb)) == NULL || dump_rom(gb, fs))
    return (1);
  get_rom_header(gb);
  if (check_rom_header(gb))
    return (1);
  fclose(fs);
  return (0);
}
