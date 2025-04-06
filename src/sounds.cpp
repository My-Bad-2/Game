#include <sounds.hpp>

namespace game {
void Normalize(raylib::Music &music, float &time_played) {
  time_played = music.GetTimePlayed() / music.GetTimeLength();

  if (time_played > 1.0f) {
    time_played = 1.0f;
  }
}

void UpdateMusic(raylib::Music &music, bool &pause, float &time_played) {
  music.Update();

  if (raylib::Keyboard::IsKeyPressed(KEY_P)) {
    pause = !pause;

    if (pause) {
      music.Pause();
    } else {
      music.Resume();
    }
  }

  Normalize(music, time_played);
}
}  // namespace game