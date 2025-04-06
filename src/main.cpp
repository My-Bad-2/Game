#include <game.hpp>

int main() {
  game::Game game = game::Game();

  while (game.IsRunning()) {
    BeginDrawing();
    game.Update();
    game.Render();
    EndDrawing();
  }

  return 0;
}