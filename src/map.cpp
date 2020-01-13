#pragma once
#include "camera.cpp"
#include "state.cpp"
#include "textures.cpp"

#define MAP_SIZE_X 10
#define MAP_SIZE_Y 6
#define TILE_SIZE 100

struct Map {
  // TODO: load from file
  // clang-format off
  int map[MAP_SIZE_X * MAP_SIZE_Y] = {
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 1, 1, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 0, 0
  };
  // clang-format on
  int mapSizeX = MAP_SIZE_X;
  int mapSizeY = MAP_SIZE_Y;
  int tileSize = TILE_SIZE;
  State &state;
  Camera &camera;

  Map(State &state, Camera &camera) : state(state), camera(camera) {}

  void renderTile(Texture &texture, int x, int y, int w, int h) {
    renderTexture(texture, x + camera.offsetX, y + camera.offsetY, w, h);
  }

  void render() {
    for (int y = 0; y < mapSizeY; y++) {
      for (int x = 0; x < mapSizeX; x++) {
        auto &texture =
          map[x + mapSizeX * y] == 0 ? textures.ground : textures.grass;

        renderTile(texture, x * tileSize, y * tileSize, tileSize, tileSize);
      }
    }
  }
};
