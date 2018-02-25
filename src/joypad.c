#include <SDL/SDL.h>
#include "joypad.h"
#include "gameboy.h"

static inline uint8_t get_p14(t_keys const keys)
{
  return (~(keys.right | (keys.left << 1) | (keys.up << 2) | (keys.down << 3)));
}

static inline uint8_t get_p15(t_keys const keys)
{
  return (~(keys.a | (keys.b << 1) | (keys.select << 2) | (keys.start << 3)));
}

uint8_t get_keys_value(uint8_t p1, t_keys const keys)
{
  if (!(p1 & 0x10)) {
      return (get_p14(keys));
  }
  if (!(p1 & 0x20)) {
      return (get_p15(keys));
  }
  if (!(p1 & 0x30)) {
      return (0xff);
  }
  return (0);
}

void        fetch_input(t_gameboy *gb)
{
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
            gb->stop = true;
            break;
        case SDL_KEYUP:
        case SDL_KEYDOWN: {
            switch (event.key.keysym.sym) {
              case SDLK_RIGHT:
                  gb->joypad.keys.right = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_LEFT:
                  gb->joypad.keys.left = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_UP:
                  gb->joypad.keys.up = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_DOWN:
                  gb->joypad.keys.down = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_a:
                  gb->joypad.keys.a = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_b:
                  gb->joypad.keys.b = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_s:
                  gb->joypad.keys.select = (event.type == SDL_KEYDOWN);
                  break;
              case SDLK_RETURN:
                  gb->joypad.keys.start = (event.type == SDL_KEYDOWN);
                  break;
              default:
                  break;
            }
            break;
        }
      }
  }
}

void init_joypad(t_gameboy *gb)
{
  (void)gb;
}

void joypad_step(t_gameboy *gb)
{
  fetch_input(gb);
}
