#include "object.hpp"
#include "util/config.hpp"

#include <iostream>
using std::cout;
using std::endl;
using SDL2pp::Rect;
using Configuration::config;

Object::Object(Vector2<float> position, Vector2<float> size) :
    m_position(position),
    m_size(size)
{
}

Rect Object::get_bounding_box() const
{
    return Rect(m_position.x, m_position.y,
                m_size.x*config->SPRITE_SCALE, m_size.y*config->SPRITE_SCALE);
}

Vector2<float> Object::get_position() const
{
    return m_position;
}

bool Object::collides_with(const Object &other) const
{
    return get_bounding_box().Intersects(other.get_bounding_box());
}

void Object::draw()
{
}
