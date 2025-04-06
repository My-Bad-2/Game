#ifndef SOUNDS_HPP
#define SOUNDS_HPP 1

#include <raylib-cpp.hpp>

namespace game {
void Normalize(raylib::Music& music, float& time_played);
void UpdateMusic(raylib::Music& music, bool& pause, float& time_played);
}  // namespace game

#endif  // SOUNDS_HPP