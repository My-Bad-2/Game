#ifndef SCENES_MODE_SELECTION_HPP
#define SCENES_MODE_SELECTION_HPP 1

#include <raylib-cpp.hpp>

#include <scenes/scenes.hpp>

namespace game::scenes {
class ModeSelection {
 public:
  void Update(scenes::Scenes& curr_scene, Mode& curr_mode);
  void Render(raylib::Window& window, Mode curr_mode);
};
}  // namespace game::scenes

#endif  // SCENES_MODE_SELECTION