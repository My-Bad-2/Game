#include <sounds.hpp>

namespace game {
void Normalize(raylib::Music &music, float &time_played) {
  // Calculate the normalized playback time (0.0 to 1.0)
  time_played = music.GetTimePlayed() / music.GetTimeLength();

  // Ensure the normalized time does not exceed 1.0
  if (time_played > 1.0f) {
    time_played = 1.0f;
  }
}

void UpdateMusic(raylib::Music &music, bool &pause, float &time_played) {
  // Update the music stream (required for raylib to process audio)
  music.Update();

  // Check if the "P" key is pressed to toggle pause/resume
  if (raylib::Keyboard::IsKeyPressed(KEY_P)) {
    pause = !pause;  // Toggle the pause state

    if (pause) {
      music.Pause();  // Pause the music if currently playing
    } else {
      music.Resume();  // Resume the music if currently paused
    }
  }

  // Normalize the playback time for consistent tracking
  Normalize(music, time_played);
}
}  // namespace game