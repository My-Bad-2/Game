#ifndef ENTITIES_ENTITY_HPP
#define ENTITIES_ENTITY_HPP 1

namespace game::entities {
class Entity {
 protected:
  float m_x, m_y;

 public:
  Entity(float x = 0, float y = 0) : m_x(x), m_y(y) {}
};
}  // namespace game::entities

#endif  // ENTITIES_ENTITY_HPP