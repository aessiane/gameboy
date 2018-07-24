#ifndef JOYPAD_H_
# define JOYPAD_H_

# include <stdint.h>

typedef struct s_gameboy t_gameboy;

enum e_keys_row {
    KR_P14 = 0x10, KR_P15 = 0x20
};

typedef struct      s_keys
{
  union {
      struct {
          uint8_t   right: 1;
          uint8_t   left: 1;
          uint8_t   up: 1;
          uint8_t   down: 1;
      };
      uint8_t       p14;
  };
  union {
      struct {
          uint8_t   a: 1;
          uint8_t   b: 1;
          uint8_t   select: 1;
          uint8_t   start: 1;
      };
      uint8_t       p15;
  };
}                   t_keys;

typedef struct      s_joypad
{
  t_keys            keys;
}                   t_joypad;

uint8_t get_keys_value(uint8_t p1, t_keys const keys);

void init_joypad(t_gameboy *gb);
void joypad_step(t_gameboy *gb);

#endif /* !JOYPAD_H_ */
