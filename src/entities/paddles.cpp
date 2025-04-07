#include <entities/ball.hpp>
#include <entities/paddles.hpp>

namespace game::entities {
void Paddle::LimitMovement(raylib::Window& window) {
  // Prevent the paddle from moving above the top edge of the window
  if (this->m_y <= 0) {
    this->m_y = 0;
  }

  const float win_height = static_cast<float>(window.GetHeight());

  // Prevent the paddle from moving below the bottom edge of the window
  if ((m_y + this->m_height) >= win_height) {
    this->m_y = win_height - this->m_height;
  }
}

void Paddle::Load(const float x, const float y) {
  // Set the initial position of the paddle
  this->m_x = x;
  this->m_y = y;
}

void Paddle::Draw() {
  // Create a rectangle representing the paddle
  raylib::Rectangle rect;
  rect.SetX(this->m_x);            // Set the x-coordinate of the paddle
  rect.SetY(this->m_y);            // Set the y-coordinate of the paddle
  rect.SetHeight(this->m_height);  // Set the height of the paddle
  rect.SetWidth(this->m_width);    // Set the width of the paddle

  // Draw the paddle with rounded corners
  rect.DrawRounded(0.5f, 6, raylib::Color::White());
}

void Paddle::Update(raylib::Window& window) {
  // Limit the paddle's movement within the window boundaries
  this->LimitMovement(window);
}

void Paddle::Update(raylib::Window& window, class Ball& ball) {
  // Make the CPU paddle slower by applying a speed multiplier
  const float speed = 0.25f;

  // Move the paddle up if the ball is above the paddle's center
  if ((this->m_y + this->m_height / 2.0f) > ball.m_y) {
    this->m_y -= this->m_speed * speed;
  }

  // Move the paddle down if the ball is below the paddle's center
  if ((this->m_y + this->m_height / 2.0f) <= ball.m_y) {
    this->m_y += this->m_speed * speed;
  }

  // Ensure the paddle stays within the window boundaries
  this->LimitMovement(window);
}

raylib::Rectangle Paddle::Get() {
  // Return a rectangle representing the paddle's position and size
  return Rectangle(this->m_x, this->m_y, this->m_width, this->m_height);
}
}  // namespace game::entities