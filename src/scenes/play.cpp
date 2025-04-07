#include <scenes/play.hpp>

namespace game::scenes {
void Play::Load(raylib::Window& window) {
  // Load sound effects for paddle and table collisions
  this->m_paddle_collision.Load("res/sounds/paddle.ogg");
  this->m_table_collision.Load("res/sounds/table.ogg");

  // Get the window dimensions
  const auto [win_width, win_height] = window.GetSize();

  // Get the height of player 1's paddle
  const float player1_height = this->m_player.GetHeight();

  // Get the width and height of player 2's paddle
  const float player2_width = this->m_player_2.GetWidth();
  const float player2_height = this->m_player_2.GetHeight();

  // Initialize player 1's paddle position (left side, vertically centered)
  this->m_player.Load(10, (win_height / 2.0f) - (player1_height / 2.0f));

  // Initialize player 2's paddle position (right side, vertically centered)
  this->m_player_2.Load(win_width - (player2_width + 10.0f),
                        (win_height / 2.0f) - (player2_height / 2.0f));

  // Initialize the ball at the center of the window
  this->m_ball.Load(window);

  // Reset the scores for both players
  this->m_score1 = this->m_score2 = 0;
}

void Play::Unload() {
  // Unload sound effects to free memory
  this->m_paddle_collision.Unload();
  this->m_table_collision.Unload();
}

void Play::Update(raylib::Window& window, scenes::Mode curr_mode) {
  using namespace scenes;

  // Player 1 controls (W and S keys)
  if (raylib::Keyboard::IsKeyDown(KEY_S)) {
    this->m_player.MoveUp(); // Move paddle up
  }

  if (raylib::Keyboard::IsKeyDown(KEY_W)) {
    this->m_player.MoveDown(); // Move paddle down
  }

  if (curr_mode == Mode::PvC) { // Player vs CPU mode
    // Update player 1's paddle
    this->m_player.Update(window);

    // Update player 2's paddle (CPU-controlled)
    this->m_player_2.Update(window, this->m_ball);

    // Update the ball's position and check for collisions
    this->m_ball.Update(window, this->m_table_collision);
    this->m_ball.CheckWinner(window, this->m_score1, this->m_score2);

    // Check if the ball collides with either paddle
    if (this->m_ball.CheckCollision(this->m_player.Get()) ||
        this->m_ball.CheckCollision(this->m_player_2.Get())) {
      this->m_paddle_collision.Play(); // Play paddle collision sound
      this->m_ball.ChangeSpeedX();    // Reverse the ball's horizontal direction
    }
  }

  if (curr_mode == Mode::PvP) { // Player vs Player mode
    // Player 2 controls (UP and DOWN arrow keys)
    if (raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
      this->m_player_2.MoveUp(); // Move paddle up
    }

    if (raylib::Keyboard::IsKeyDown(KEY_UP)) {
      this->m_player_2.MoveDown(); // Move paddle down
    }

    // Update both paddles
    this->m_player.Update(window);
    this->m_player_2.Update(window);

    // Update the ball's position and check for collisions
    this->m_ball.Update(window, this->m_table_collision);
    this->m_ball.CheckWinner(window, this->m_score1, this->m_score2);

    // Check if the ball collides with either paddle
    if (this->m_ball.CheckCollision(this->m_player.Get()) ||
        this->m_ball.CheckCollision(this->m_player_2.Get())) {
      this->m_paddle_collision.Play(); // Play paddle collision sound
      this->m_ball.ChangeSpeedX();    // Reverse the ball's horizontal direction
    }
  }
}

void Play::Render(raylib::Window& window) {
  const int width = window.GetWidth();
  const int height = window.GetHeight();

  // Draw the center line
  DrawLine(width / 2, 0, width / 2, height, RAYWHITE);

  // Draw player 1's score
  const char* fmt_txt = TextFormat("%i", this->m_score1);
  DrawText(fmt_txt, (width / 4) - 20, 0, 80, RAYWHITE);

  // Draw player 2's score
  fmt_txt = TextFormat("%i", this->m_score2);
  DrawText(fmt_txt, (3 * (width / 4)) - 20, 0, 80, RAYWHITE);

  // Draw player 1's paddle
  this->m_player.Draw();

  // Draw player 2's paddle
  this->m_player_2.Draw();

  // Draw the ball
  this->m_ball.Draw();
}
}  // namespace game::scenes