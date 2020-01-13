#pragma once
#include "sdl.cpp"

struct Camera {
  int offsetX = 0;
  int offsetY = 0;

  void focusOn(int x, int y, int w, int h) {
    offsetX = sdl.windowWidth / 2 - x - w / 2;
    offsetY = sdl.windowHeight / 2 - y - h / 2;
  }
};
