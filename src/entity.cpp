#pragma once
#include "map.cpp"
#include "textures.cpp"
#include <pch.hpp>

static int entitySpeed = 8;

struct Entity {
  std::string id;
  Map &map;
  Texture &texture;
  int x, y, w, h;
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;

  Entity(
    std::string id,
    Map &map,
    Texture &texture,
    int x,
    int y,
    int width = -1,
    int height = -1)
      : id(id), map(map), texture(texture), x(x), y(y) {
    w = width == -1 ? map.tileSize : width;
    h = height == -1 ? map.tileSize : height;
  }

  void update() {
    if (moveUp) {
      y -= entitySpeed;
    }
    if (moveLeft) {
      x -= entitySpeed;
    }
    if (moveDown) {
      y += entitySpeed;
    }
    if (moveRight) {
      x += entitySpeed;
    }
  }

  void render() {
    map.renderTile(texture, x, y, w, h);
  };
};
