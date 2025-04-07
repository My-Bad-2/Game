#include <utils.hpp>

#include <scenes/mode_selection.hpp>

namespace game::scenes {
void ModeSelection::Update(scenes::Scenes& curr_scene, Mode& curr_mode) {
  // Check if the "W" or "UP" key is pressed to select Player vs CPU mode
  if (raylib::Keyboard::IsKeyDown(KEY_W) ||
      raylib::Keyboard::IsKeyDown(KEY_UP)) {
    curr_mode = Mode::PvC;  // Set the current mode to Player vs CPU
  }

  // Check if the "S" or "DOWN" key is pressed to select Player vs Player mode
  if (raylib::Keyboard::IsKeyDown(KEY_S) ||
      raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
    curr_mode = Mode::PvP;  // Set the current mode to Player vs Player
  }

  // Check if the "ENTER" key is pressed to start the game
  if (raylib::Keyboard::IsKeyDown(KEY_ENTER)) {
    curr_scene = scenes::Scenes::Game;  // Switch to the Game scene
  }
}

void ModeSelection::Render(raylib::Window& window, Mode curr_mode) {
  // Draw the title text at the top of the screen
  DrawScreenText("Select Game Mode", (window.GetWidth() / 2),
                 static_cast<int>(window.GetHeight() / 2.5), SKYBLUE);

  // Highlight "Player vs CPU" if it is the current mode
  if (curr_mode == Mode::PvC) {
    DrawScreenText("* Player vs CPU", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 2.2), SKYBLUE);
  } else {
    // Draw "Player vs CPU" in a normal color if it is not the current mode
    DrawScreenText("Player vs CPU", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 2.2), RAYWHITE);
  }

  // Highlight "Player vs Player" if it is the current mode
  if (curr_mode == Mode::PvP) {
    DrawScreenText("* Player vs Player", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 1.8), SKYBLUE);
  } else {
    // Draw "Player vs Player" in a normal color if it is not the current mode
    DrawScreenText("Player vs Player", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 1.8), RAYWHITE);
  }

  // Draw instructions to press ENTER to start the game
  DrawScreenText("Hit ENTER to start playing", window.GetWidth() / 2,
                 static_cast<int>(window.GetHeight() / 1.2), GRAY, 40);
}
}  // namespace game::scenes