#pragma once
#include "sdl.cpp"
#include "sizes.cpp"
#include "textures.cpp"
#include <pch.hpp>

static Font loadFont(const std::string &fontType, const int &fontSize) {
  auto source = "./assets/fonts/" + fontType + ".ttf";
  auto font = Font(TTF_OpenFont(source.c_str(), fontSize), sdlDeleter);
  if (!font) {
    std::cout << TTF_GetError() << std::endl;
    exit(1);
  }
  return font;
}

struct Fonts {
  Font medium = loadFont("unibody_8", size.medium);
  Font mediumBold = loadFont("unibody_8_bold", size.medium);
  Font mediumItalic = loadFont("unibody_8_italic", size.medium);
  Font large = loadFont("unibody_8", size.large);
  Font largeBold = loadFont("unibody_8_bold", size.large);
  Font largeItalic = loadFont("unibody_8_italic", size.large);
};

static Fonts fonts;
