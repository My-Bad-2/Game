#include <entities/ball.hpp>

namespace game::entities {
void Ball::Load(raylib::Window& window) {
  this->m_x = static_cast<float>(window.GetWidth()) / 2.0f;
  this->m_y = static_cast<float>(window.GetHeight()) / 2.0f;
}

void Ball::Update(raylib::Window& window, raylib::Sound& collision_sound) {
  this->m_x += static_cast<float>(this->m_speed_x);
  this->m_y += static_cast<float>(this->m_speed_y);

  if ((this->m_x + this->m_radius >= window.GetWidth()) ||
      (this->m_x - this->m_radius <= 0)) {
    collision_sound.Play();
    this->m_speed_x = -this->m_speed_x;
  }

  if (((this->m_y + this->m_radius) >= window.GetHeight()) ||
      ((this->m_y - this->m_radius) <= 0)) {
    collision_sound.Play();
    this->m_speed_y = -this->m_speed_y;
  }
}

void Ball::Draw() {
  DrawCircle(this->m_x, this->m_y, this->m_radius, raylib::Color::Yellow());
}

void Ball::CheckWinner(raylib::Window& window, size_t& score1, size_t& score2) {
  if (this->m_x + this->m_radius >= window.GetWidth()) {
    score1++;
    this->Reset(window);
  }

  if (this->m_x - this->m_radius <= 0) {
    score2++;
    this->Reset(window);
  }
}

void Ball::Reset(raylib::Window& window) {
  this->m_x = static_cast<float>(window.GetWidth()) / 2.0f;
  this->m_y = static_cast<float>(window.GetHeight()) / 2.0f;

  const int speed_choices[] = {-1, 1};

  this->m_speed_x *= speed_choices[GetRandomValue(0, 1)];
  this->m_speed_y *= speed_choices[GetRandomValue(0, 1)];
}

bool Ball::CheckCollision(raylib::Rectangle rect) {
  return CheckCollisionCircleRec(Vector2(this->m_x, this->m_y), this->m_radius,
                                 rect);
}
}  // namespace game::entities