#pragma once
#include <SDL2/SDL.h>

struct Colors {
  SDL_Color white = { 255, 255, 255, 255 };
  SDL_Color black = { 0, 0, 0, 255 };
  SDL_Color midnightBlueColor = { 44, 62, 80, 255 };
};

static Colors colors;
