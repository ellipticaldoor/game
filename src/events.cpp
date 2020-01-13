#include "dialogue/dialogueUI.cpp"
#include "entity.cpp"
#include "state.cpp"
#include <pch.hpp>

static SDL_Event event;

static void events(State &state, Dialogue &dialogue, Entity &player) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        state.quit = true;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          state.quit = true;
        }

        if (state.gameMode == GameMode::normal) {
          if (event.key.keysym.sym == SDLK_w) {
            player.moveUp = true;
          }
          if (event.key.keysym.sym == SDLK_a) {
            player.moveLeft = true;
          }
          if (event.key.keysym.sym == SDLK_s) {
            player.moveDown = true;
          }
          if (event.key.keysym.sym == SDLK_d) {
            player.moveRight = true;
          }
        }

        if (state.gameMode == GameMode::dialogue) {
          if (
            event.key.keysym.sym == SDLK_SPACE ||
            event.key.keysym.sym == SDLK_RETURN) {
            dialogue.acceptOption();
          }
          if (event.key.keysym.sym == SDLK_UP) {
            dialogue.selectPreviousOption();
          }
          if (event.key.keysym.sym == SDLK_DOWN) {
            dialogue.selectNextOption();
          }
        }

        if (event.key.keysym.sym == SDLK_m) {
          player.moveUp = false;
          player.moveLeft = false;
          player.moveDown = false;
          player.moveRight = false;
          state.gameMode = state.gameMode == GameMode::normal
            ? GameMode::dialogue
            : GameMode::normal;
        }
        break;
      case SDL_KEYUP:
        if (state.gameMode == GameMode::normal) {
          if (event.key.keysym.sym == SDLK_w) {
            player.moveUp = false;
          }
          if (event.key.keysym.sym == SDLK_a) {
            player.moveLeft = false;
          }
          if (event.key.keysym.sym == SDLK_s) {
            player.moveDown = false;
          }
          if (event.key.keysym.sym == SDLK_d) {
            player.moveRight = false;
          }
        }
        break;
      default:
        break;
    }
  }
}
