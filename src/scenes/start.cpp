#include <utils.hpp>

#include <scenes/start.hpp>

namespace game::scenes {
void Start::Update(Scenes& curr_scene) {
  // Check if the SPACE key is pressed
  if (raylib::Keyboard::IsKeyDown(KEY_SPACE)) {
    // Switch to the Mode Selection scene
    curr_scene = Scenes::Selection;
  }
}

void Start::Render(raylib::Window& window) {
  // Draw the game title at the top of the screen
  DrawScreenText("Ping Pong", window.GetWidth() / 2, window.GetHeight() / 3,
                 raylib::Color(199, 14, 14), 120);

  // Draw instructions to press SPACE to start the game
  DrawScreenText("Press SPACE to start", window.GetWidth() / 2,
                 static_cast<int>(window.GetHeight() / 1.5), RAYWHITE, 60);
}
}  // namespace game::scenes