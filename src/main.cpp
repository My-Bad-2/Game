#include <game.hpp>

int main() {
  // Create an instance of the Game class
  game::Game game = game::Game();

  // Main game loop
  while (game.IsRunning()) {
    game.Update();  // Update the game state

    BeginDrawing();  // Start rendering the frame
    game.Render();   // Render the current frame
    EndDrawing();    // End rendering the frame and display it
  }

  return 0;
}