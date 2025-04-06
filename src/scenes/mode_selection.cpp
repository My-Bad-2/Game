#include <utils.hpp>

#include <scenes/mode_selection.hpp>

namespace game::scenes {
void ModeSelection::Update(scenes::Scenes& curr_scene, Mode& curr_mode) {
  if (raylib::Keyboard::IsKeyDown(KEY_W) ||
      raylib::Keyboard::IsKeyDown(KEY_UP)) {
    curr_mode = Mode::PvC;
  }

  if (raylib::Keyboard::IsKeyDown(KEY_S) ||
      raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
    curr_mode = Mode::PvP;
  }

  if (raylib::Keyboard::IsKeyDown(KEY_ENTER)) {
    curr_scene = scenes::Scenes::Game;
  }
}

// void ModeSelection::Render(raylib::Window& window, Mode curr_mode) {
//   DrawScreenText("Select Game Mode", (window.GetWidth() / 2),
//                  static_cast<int>(window.GetHeight() / 2.5), SKYBLUE);

//   if (curr_mode == Mode::PvC) {
//     DrawScreenText("* Player vs CPU", window.GetWidth() / 2,
//                    static_cast<int>(window.GetHeight() / 2.5), SKYBLUE);
//   } else {
//     DrawScreenText("Player vs CPU", window.GetWidth() / 2,
//                    static_cast<int>(window.GetHeight() / 2.5), RAYWHITE);
//   }

//   if (curr_mode == Mode::PvP) {
//     DrawScreenText("* Player vs Player", window.GetWidth() / 2,
//                    window.GetHeight() / 2, SKYBLUE);
//   } else {
//     DrawScreenText("Player vs Player", window.GetWidth() / 2,
//                    window.GetHeight() / 2, RAYWHITE);
//   }

//   DrawScreenText("Hit ENTER to start playing", window.GetWidth() / 2,
//                  static_cast<int>(window.GetHeight() / 1.2), GRAY, 40);
// }

void ModeSelection::Render(raylib::Window& window, Mode curr_mode) {
  DrawScreenText("Select Game Mode", (window.GetWidth() / 2),
                 static_cast<int>(window.GetHeight() / 2.5), SKYBLUE);

  // Adjusted vertical positions to avoid overlap
  if (curr_mode == Mode::PvC) {
    DrawScreenText("* Player vs CPU", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 2.2), SKYBLUE);
  } else {
    DrawScreenText("Player vs CPU", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 2.2), RAYWHITE);
  }

  if (curr_mode == Mode::PvP) {
    DrawScreenText("* Player vs Player", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 1.8), SKYBLUE);
  } else {
    DrawScreenText("Player vs Player", window.GetWidth() / 2,
                   static_cast<int>(window.GetHeight() / 1.8), RAYWHITE);
  }

  DrawScreenText("Hit ENTER to start playing", window.GetWidth() / 2,
                 static_cast<int>(window.GetHeight() / 1.2), GRAY, 40);
}
}  // namespace game::scenes