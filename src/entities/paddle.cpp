#include <entities/ball.hpp>
#include <entities/paddles.hpp>

namespace game::entities {
void Paddle::LimitMovement(raylib::Window& window) {
  if (this->m_y <= 0) {
    this->m_y = 0;
  }

  const float win_height = static_cast<float>(window.GetHeight());

  if ((m_y + this->m_height) >= win_height) {
    this->m_y = win_height - this->m_height;
  }
}

void Paddle::Load(const float x, const float y) {
  this->m_x = x;
  this->m_y = y;
}

void Paddle::Draw() {
  raylib::Rectangle rect;
  rect.SetX(this->m_x);
  rect.SetY(this->m_y);
  rect.SetHeight(this->m_height);
  rect.SetWidth(this->m_width);

  rect.DrawRounded(0.5f, 6, raylib::Color::White());
}

void Paddle::Update(raylib::Window& window) { this->LimitMovement(window); }

void Paddle::Update(raylib::Window& window, class Ball& ball) {
  // Introduce a miss chance
  const int miss_chance = 10;  // 10% chance to miss

  if (GetRandomValue(0, 99) < miss_chance) {
    return;
  }

  // Normal paddle movement logic
  if ((this->m_y + this->m_height / 2.0f) > ball.m_y) {
    this->m_y -= this->m_speed;
  }

  if ((this->m_y + this->m_height / 2.0f) <= ball.m_y) {
    this->m_y += this->m_speed;
  }

  this->LimitMovement(window);
}

raylib::Rectangle Paddle::Get() {
  return Rectangle(this->m_x, this->m_y, this->m_width, this->m_height);
}
}  // namespace game::entities