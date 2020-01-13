#pragma once
#include "colors.cpp"
#include "textures.cpp"
#include <pch.hpp>

struct Text {
  Font font;
  Surface surface;
  Texture texture;
  std::string text;
  SDL_Color &color;
  int w, h;

  void updateTexture() {
    surface = Surface(TTF_RenderUTF8_Blended(font.get(), text.c_str(), color));
    texture = Texture(
      SDL_CreateTextureFromSurface(sdl.renderer.get(), surface.get()),
      sdlDeleter);
    SDL_QueryTexture(texture.get(), NULL, NULL, &w, &h);
  }

  Text(
    Font &font,
    const std::string &text = "",
    SDL_Color &color = colors.midnightBlueColor)
      : font(font), text(text), color(color) {
    updateTexture();
  }

  void render(const std::string &newText, int x, int y) {
    bool shouldUpdateTexture = text != newText;

    if (shouldUpdateTexture) {
      text = newText;
      updateTexture();
    }

    renderTexture(texture, x, y, w, h);
  }
};
