#ifndef ENTITIES_BALL_HPP
#define ENTITIES_BALL_HPP

#include <raylib-cpp.hpp>

#include <entities/entity.hpp>

namespace game::entities {
class Ball : Entity {
 private:
  friend class Paddle;

  int m_speed_x = 10;
  int m_speed_y = 5;

  float m_radius = 20;

 public:
  void Load(raylib::Window& window);

  void Update(raylib::Window& window, raylib::Sound& collision_sound);
  void Draw();

  void CheckWinner(raylib::Window& window, size_t& score1, size_t& score2);
  void Reset(raylib::Window&);

  void ChangeSpeedX() {
    this->m_speed_x *= -1;
  }

  bool CheckCollision(raylib::Rectangle rect);
};
}  // namespace game::entities

#endif  // ENTITIES_BALL_HPP