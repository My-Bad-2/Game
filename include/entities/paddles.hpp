#include <raylib-cpp.hpp>

#include <entities/entity.hpp>

namespace game::entities {
class Paddle : Entity {
 private:
  friend class GamePlay;

  float m_speed = 10;
  float m_width = 20;
  float m_height = 100;

  void LimitMovement(raylib::Window& window);

 public:
  Paddle() : Entity() {}

  float GetHeight() const { return this->m_height; }

  float GetWidth() const { return this->m_width; }

  void Load(const float x, const float y);

  void Update(raylib::Window& window);
  void Update(raylib::Window& window, class Ball& ball);
  void Draw();

  void MoveUp() { this->m_y += this->m_speed; }

  void MoveDown() { this->m_y -= this->m_speed; }

  raylib::Rectangle Get();
};
}  // namespace game::entities