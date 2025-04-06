#ifndef SCENES_PLAY_HPP
#define SCENES_PLAY_HPP 1

#include <scenes/scenes.hpp>

#include <entities/ball.hpp>
#include <entities/paddles.hpp>

namespace game::scenes {
class Play {
 private:
  raylib::Sound m_paddle_collision;
  raylib::Sound m_table_collision;

  entities::Paddle m_player, m_player_2;
  entities::Ball m_ball;

  size_t m_score1, m_score2;

 public:
  void Load(raylib::Window& window);
  void Unload();
  void Update(raylib::Window& window, scenes::Mode curr_mode);
  void Render(raylib::Window& window);
};
}  // namespace game

#endif  // SCENES_PLAY_HPP