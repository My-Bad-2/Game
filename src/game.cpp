#include <game.hpp>
#include <raylib-cpp.hpp>

namespace game {
void Game::Initialize() {
  // Initialize the game window with specified dimensions and title
  this->m_window.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Ping Pong");

  // Initialize the audio device for sound playback
  this->m_audio_device.Init();

  // Disable the default exit key (e.g., ESC) to prevent accidental exits
  this->m_window.SetExitKey(KEY_NULL);

  // Set the target frames per second to 60 for smooth gameplay
  this->m_window.SetTargetFPS(60);

  // Load and set the window icon
  raylib::Image icon("res/icon.png");
  this->m_window.SetIcon(icon);
  icon.Unload();  // Unload the icon image from memory after setting it

  // Set the initial game mode to Pclayer vs CPU
  this->m_curr_mode = scenes::Mode::PvC;

  // Set the initial scene to the Start screen
  this->m_curr_scene = scenes::Scenes::Start;

  // Load the background music and set its volume
  this->m_sound_track.Load("res/sounds/jazz-sound-track.mp3");
  this->m_sound_track.SetVolume(0.1f);  // Set volume to 10%
  this->m_sound_track.Play();           // Start playing the background music
}

Game::~Game() {
  // Ensure the music is stopped before unloading
  if (this->m_sound_track.IsPlaying()) {
    this->m_sound_track.Stop();
  }

  // Unload the music track from memory
  this->m_sound_track.Unload();

  // Unload the game resources (e.g., gameplay elements)
  this->m_play.Unload();

  // Close the audio device (commented out due to potential freezing issues)
  // if (this->m_audio_device.IsReady()) {
  //   this->m_audio_device.Close();
  // }

  // Close the game window if it is still open
  if (this->m_window.IsReady()) {
    this->m_window.Close();
  }
}

void Game::Update() {
  // Update the background music (e.g., loop or handle playback state)
  UpdateMusic(this->m_sound_track, this->m_pause_music, this->m_time_played);

  // Handle updates based on the current scene
  switch (this->m_curr_scene) {
    case scenes::Scenes::Start:
      // Update the Start scene
      this->m_start.Update(this->m_curr_scene);
      break;
    case scenes::Scenes::Selection:
      // Update the Mode Selection scene
      this->m_mode_selection.Update(this->m_curr_scene, this->m_curr_mode);
      break;
    case scenes::Scenes::Game:
      // Update the main gameplay scene
      this->m_play.Update(this->m_window, this->m_curr_mode);
      break;
  }
}

void Game::Render() {
  // Clear the screen with a black background
  this->m_window.ClearBackground(BLACK);

  // Render the current scene
  switch (this->m_curr_scene) {
    case scenes::Scenes::Start:
      // Render the Start scene
      this->m_start.Render(this->m_window);
      break;
    case scenes::Scenes::Selection:
      // Render the Mode Selection scene
      this->m_mode_selection.Render(this->m_window, this->m_curr_mode);
      break;
    case scenes::Scenes::Game:
      // Render the main gameplay scene
      this->m_play.Render(this->m_window);
      break;
  }
}

bool Game::IsRunning() {
  // Check if the game window is still open and the audio device is ready
  return !this->m_window.ShouldClose() && this->m_audio_device.IsReady();
}
}  // namespace game