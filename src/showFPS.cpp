#pragma once
#include "sdl.cpp"

Uint32 lastTime = SDL_GetTicks();
Uint32 fps = 0;
Uint32 fpsCount = 0;

char windowTitle[80];

void showFPS() {
  fpsCount++;
  if (lastTime < SDL_GetTicks() - 1000) {
    lastTime = SDL_GetTicks();
    fps = fpsCount == 61 ? 60 : fpsCount;
    fpsCount = 0;
  }

  sprintf(windowTitle, "%i FPS", fps);
  SDL_SetWindowTitle(sdl.window.get(), windowTitle);
}
