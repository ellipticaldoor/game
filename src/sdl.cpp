#pragma once
#include <pch.hpp>

static const int WINDOW_WIDTH = 1440;
static const int WINDOW_HEIGHT = 810;

struct SDLDeleter {
  void operator()(SDL_Window *window) const {
    SDL_DestroyWindow(window);
    // std::cout << "SDL_Window destroyed \n";
  }
  void operator()(SDL_Renderer *renderer) const {
    SDL_DestroyRenderer(renderer);
    // std::cout << "SDL_Renderer destroyed \n";
  }
  void operator()(SDL_Texture *texture) const {
    SDL_DestroyTexture(texture);
    // std::cout << "SDL_Texture destroyed \n";
  }
  void operator()(SDL_Surface *surface) const {
    SDL_FreeSurface(surface);
    // std::cout << "SDL_Surface destroyed \n";
  }
  void operator()(TTF_Font *font) const {
    TTF_CloseFont(font);
    // std::cout << "TTF_CloseFont destroyed \n";
  }
};

static SDLDeleter sdlDeleter;

using Window = std::unique_ptr<SDL_Window, SDLDeleter>;
using Renderer = std::unique_ptr<SDL_Renderer, SDLDeleter>;
using Surface = std::unique_ptr<SDL_Surface, SDLDeleter>;
using Texture = std::shared_ptr<SDL_Texture>;
using Font = std::shared_ptr<TTF_Font>;

struct SDL {
  Window window;
  Renderer renderer;
  int windowWidth = WINDOW_WIDTH;
  int windowHeight = WINDOW_HEIGHT;

  SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      std::cout << SDL_GetError() << std::endl;
      exit(1);
    }

    window = Window(SDL_CreateWindow(
      "Game",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      0));

    if (!window) {
      std::cout << SDL_GetError() << std::endl;
      SDL_Quit();
      exit(1);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
      std::cout << IMG_GetError() << std::endl;
      SDL_Quit();
      exit(1);
    }

    if (TTF_Init() == -1) {
      std::cout << TTF_GetError() << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(1);
    }

    Uint32 renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    renderer = Renderer(SDL_CreateRenderer(window.get(), -1, renderFlags));
    if (!renderer) {
      std::cout << SDL_GetError() << std::endl;
      TTF_Quit();
      IMG_Quit();
      SDL_Quit();
      exit(1);
    }
  }

  ~SDL() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
  }
};

static SDL sdl;
