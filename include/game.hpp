#ifndef GAME_HPP
#define GAME_HPP 1

#include <sounds.hpp>

#include <scenes/mode_selection.hpp>
#include <scenes/play.hpp>
#include <scenes/start.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

namespace game {
class Game {
 private:
  raylib::Music m_sound_track;

  float m_time_played = 0;
  bool m_pause_music;

  scenes::Scenes m_curr_scene;
  scenes::Mode m_curr_mode;

  scenes::Start m_start;
  scenes::ModeSelection m_mode_selection;
  scenes::Play m_play;

  raylib::Window m_window;
  raylib::AudioDevice m_audio_device;

 public:
  Game() {
    this->Initialize();
    this->LoadRes();
  }

  void Initialize();
  ~Game();

  void LoadRes() { this->m_play.Load(this->m_window); }

  void Update();
  void Render();

  bool IsRunning();
};
}  // namespace game

#endif  // GAME_HPP