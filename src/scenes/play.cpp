#include <scenes/play.hpp>

namespace game::scenes {
void Play::Load(raylib::Window& window) {
  this->m_paddle_collision.Load("res/sounds/paddle.ogg");
  this->m_table_collision.Load("res/sounds/table.ogg");

  const auto [win_width, win_height] = window.GetSize();

  const float player1_height = this->m_player.GetHeight();

  const float player2_width = this->m_player_2.GetWidth();
  const float player2_height = this->m_player_2.GetHeight();

  this->m_player.Load(10, (win_height / 2.0f) - (player1_height / 2.0f));

  this->m_player_2.Load(win_width - (player2_width + 10.0f),
                        (win_height / 2.0f) - (player2_height / 2.0f));

  this->m_ball.Load(window);

  this->m_score1 = this->m_score2 = 0;
}

void Play::Unload() {
  this->m_paddle_collision.Unload();
  this->m_table_collision.Unload();
}

void Play::Update(raylib::Window& window, scenes::Mode curr_mode) {
  using namespace scenes;

  if (raylib::Keyboard::IsKeyDown(KEY_S)) {
    this->m_player.MoveUp();
  }

  if (raylib::Keyboard::IsKeyDown(KEY_W)) {
    this->m_player.MoveDown();
  }

  if (curr_mode == Mode::PvC) {
    this->m_player.Update(window);
    this->m_player_2.Update(window, this->m_ball);

    this->m_ball.Update(window, this->m_table_collision);
    this->m_ball.CheckWinner(window, this->m_score1, this->m_score2);

    if (this->m_ball.CheckCollision(this->m_player.Get()) ||
        this->m_ball.CheckCollision(this->m_player_2.Get())) {
      this->m_paddle_collision.Play();
      this->m_ball.ChangeSpeedX();
    }
  }

  if (curr_mode == Mode::PvP) {
    if (raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
      this->m_player_2.MoveUp();
    }

    if (raylib::Keyboard::IsKeyDown(KEY_UP)) {
      this->m_player_2.MoveDown();
    }

    this->m_player.Update(window);
    this->m_player_2.Update(window, this->m_ball);

    this->m_ball.Update(window, this->m_table_collision);
    this->m_ball.CheckWinner(window, this->m_score1, this->m_score2);

    if (this->m_ball.CheckCollision(this->m_player.Get()) ||
        this->m_ball.CheckCollision(this->m_player_2.Get())) {
      this->m_paddle_collision.Play();
      this->m_ball.ChangeSpeedX();
    }
  }
}

void Play::Render(raylib::Window& window) {
  const int width = window.GetWidth();
  const int height = window.GetHeight();

  DrawLine(width / 2, 0, width / 2, height, RAYWHITE);

  const char* fmt_txt = TextFormat("%i", this->m_score1);
  DrawText(fmt_txt, (width / 4) - 20, 0, 80, RAYWHITE);

  fmt_txt = TextFormat("%i", this->m_score2);
  DrawText(fmt_txt, (3 * (width / 4)) - 20, 0, 80, RAYWHITE);

  this->m_player.Draw();
  this->m_player_2.Draw();

  this->m_ball.Draw();
}
}  // namespace game::scenes