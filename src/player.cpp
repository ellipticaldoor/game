#pragma once
#include "camera.cpp"
#include "entity.cpp"
#include "map.cpp"
#include "sdl.cpp"
#include "state.cpp"

static void updatePlayer(State &state, Camera &camera, Entity &player) {
  if (state.gameMode == GameMode::normal) {
    player.update();
  }
  camera.focusOn(player.x, player.y, player.w, player.h);
}
