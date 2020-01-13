#include "camera.cpp"
#include "dialogue/dialogueUI.cpp"
#include "entity.cpp"
#include "events.cpp"
#include "map.cpp"
#include "player.cpp"
#include "sdl.cpp"
#include "showFPS.cpp"
#include "state.cpp"

int main() {
  State state;
  Camera camera;
  Map map(state, camera);
  Entity player("player", map, textures.player, 0, 0);
  Entity npc("npc", map, textures.npc, 3 * map.tileSize, 4 * map.tileSize);
  Dialogue dialogue;

  while (!state.quit) {
    events(state, dialogue, player);
    updatePlayer(state, camera, player);

    SDL_RenderClear(sdl.renderer.get());

    map.render();
    npc.render();
    player.render();

    if (state.gameMode == GameMode::dialogue) {
      dialogue.render();
    }

    SDL_RenderPresent(sdl.renderer.get());

    showFPS();
  }
}
