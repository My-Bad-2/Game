#ifndef UTILS_HPP
#define UTILS_HPP 1

#include <raylib-cpp.hpp>

namespace game {
inline void DrawScreenText(const char* txt, int width, int height,
                           raylib::Color color, int font_size = 50) {
  raylib::DrawText(txt, width - (raylib::MeasureText(txt, font_size) / 2), height,
                   font_size, color);
}
}  // namespace game

#endif  // UTILS_HPP