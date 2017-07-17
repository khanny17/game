#include "object.hpp"
#include "util/config.hpp"

#include <iostream>
using std::cout;
using std::cerr;
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

Direction4 Object::get_collision_side(const Object &other) const
{
    int amtRight, amtLeft, amtTop, amtBottom;
    amtRight = get_bounding_box().GetX2() - other.get_position().x;
    amtLeft = other.get_bounding_box().GetX2() - m_position.x;
    amtTop = other.get_bounding_box().GetY2() - m_position.y;
    amtBottom = get_bounding_box().GetY2() - other.get_position().y;

    int vals[4] = { abs(amtRight), abs(amtLeft), abs(amtTop), abs(amtBottom) };
    int lowest = vals[0];
    for (int i = 0; i < 4; i++) {
        if (vals[i] < lowest) {
            lowest = vals[i];
        }
    }

    if(lowest == abs(amtRight)) {
        return RIGHT;
    }
    else if(lowest == abs(amtLeft)) {
        return LEFT;
    }
    else if(lowest == abs(amtTop)) {
        return UP;
    }
    else if(lowest == abs(amtBottom)) {
        return DOWN;
    }
    else {
        cerr << "FATAL: How did this even happen?" << endl;   
        throw "Shit";
    }
}
