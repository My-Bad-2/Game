#ifndef SCENES_SCENES_HPP
#define SCENES_SCENES_HPP 1

namespace game::scenes {
enum class Scenes {
  Start = 0,
  Selection = 1,
  Game = 2,
};

enum class Mode {
  PvC,
  PvP,
};
}

#endif  // SCENES_SCENES_HPP