#include <entities/ball.hpp>

namespace game::entities {
void Ball::Load(raylib::Window& window) {
  // Set the initial position of the ball to the center of the window
  this->m_x = static_cast<float>(window.GetWidth()) / 2.0f;
  this->m_y = static_cast<float>(window.GetHeight()) / 2.0f;
}

void Ball::Update(raylib::Window& window, raylib::Sound& collision_sound) {
  // Update the ball's position based on its speed
  this->m_x += static_cast<float>(this->m_speed_x);
  this->m_y += static_cast<float>(this->m_speed_y);

  // Check for collisions with the left or right edges of the window
  if ((this->m_x + this->m_radius >= window.GetWidth()) ||  // Right edge
      (this->m_x - this->m_radius <= 0)) {                  // Left edge
    collision_sound.Play();              // Play collision sound
    this->m_speed_x = -this->m_speed_x;  // Reverse horizontal direction
  }

  // Check for collisions with the top or bottom edges of the window
  if (((this->m_y + this->m_radius) >= window.GetHeight()) ||  // Bottom edge
      ((this->m_y - this->m_radius) <= 0)) {                   // Top edge
    collision_sound.Play();              // Play collision sound
    this->m_speed_y = -this->m_speed_y;  // Reverse vertical direction
  }
}

void Ball::Draw() {
  // Draw the ball as a yellow circle
  DrawCircle(this->m_x, this->m_y, this->m_radius, raylib::Color::Yellow());
}

void Ball::CheckWinner(raylib::Window& window, size_t& score1, size_t& score2) {
  // Check if the ball has passed the right edge (player 1 scores)
  if (this->m_x + this->m_radius >= window.GetWidth()) {
    score1++;             // Increment player 1's score
    this->Reset(window);  // Reset the ball to the center
  }

  // Check if the ball has passed the left edge (player 2 scores)
  if (this->m_x - this->m_radius <= 0) {
    score2++;             // Increment player 2's score
    this->Reset(window);  // Reset the ball to the center
  }
}

void Ball::Reset(raylib::Window& window) {
  // Reset the ball's position to the center of the window
  this->m_x = static_cast<float>(window.GetWidth()) / 2.0f;
  this->m_y = static_cast<float>(window.GetHeight()) / 2.0f;

  // Randomly choose the initial direction for the ball's speed
  const int speed_choices[] = {-1, 1};
  this->m_speed_x *= speed_choices[GetRandomValue(0, 1)];
  this->m_speed_y *= speed_choices[GetRandomValue(0, 1)];
}

bool Ball::CheckCollision(raylib::Rectangle rect) {
  // Check if the ball collides with a given rectangle (e.g., paddle)
  return CheckCollisionCircleRec(Vector2(this->m_x, this->m_y), this->m_radius,
                                 rect);
}
}  // namespace game::entities