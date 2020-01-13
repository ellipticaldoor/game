#pragma once
#include "sdl.cpp"
#include <pch.hpp>

static void renderTexture(Texture &texture, int x, int y, int w, int h) {
  SDL_Rect dest = { x, y, w, h };
  SDL_RenderCopy(sdl.renderer.get(), texture.get(), NULL, &dest);
}

static Texture loadTexture(const std::string &fileName) {
  auto source = "./assets/textures/" + fileName + ".png";
  auto texture =
    Texture(IMG_LoadTexture(sdl.renderer.get(), source.c_str()), sdlDeleter);

  if (!texture) {
    std::cout << SDL_GetError() << std::endl;
    exit(1);
  }

  return texture;
}

struct Textures {
  Texture player = loadTexture("player");
  Texture npc = loadTexture("npc");
  Texture ground = loadTexture("ground");
  Texture grass = loadTexture("grass");
  Texture dialogueBox = loadTexture("dialogueBox");
};

static Textures textures;
