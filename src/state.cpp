#pragma once

enum class GameMode {
  normal,
  dialogue,
};

struct State {
  bool quit = false;
  GameMode gameMode = GameMode::dialogue;
};
