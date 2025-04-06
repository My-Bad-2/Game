#ifndef SCENES_START_HPP
#define SCENES_START_HPP 1

#include <raylib-cpp.hpp>

#include <scenes/scenes.hpp>

namespace game::scenes {
class Start {
 public:
  void Update(Scenes& curr_scene);
  void Render(raylib::Window& window);
};
}  // namespace game::scenes

#endif  // SCENES_START_HPP