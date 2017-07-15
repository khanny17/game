#include "object.hpp"

Object::Object(Vector2<float> position, Vector2<float> size) :
    m_position(position),
    m_size(size),
    m_bounding_box(position.x, position.y, size.x, size.y)
{
}

Vector2<float> Object::get_position() const
{
    return m_position;
}

bool Object::collides_with(const Object &other) const
{
    return m_bounding_box.Intersects(other.m_bounding_box);
}
