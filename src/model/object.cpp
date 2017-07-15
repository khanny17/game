#include "object.hpp"


Object::Object(Vector2 position) :
    m_position(position)
{
}

Vector2 Object::get_position() const
{
    return m_position;
}
