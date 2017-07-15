#pragma once

#include "util/vector2.hpp"
#include <SDL2pp/Rect.hh>

/**
 * This is really a placeholder, I haven't put thought into
 * design for the things that will exist in the world besides
 * the chunks and tiles. In general though this is atm the 
 * root level class for a thing that shows up on the screen
 */
class Object
{
public:
    Object(Vector2<float> position, Vector2<float> size);
    Object(const Object &other) = delete;

    virtual void update(float elapsed_time) = 0;
    Vector2<float> get_position() const;
    bool collides_with(const Object &other) const;

protected:
    Vector2<float> m_position;
    Vector2<float> m_size;
    SDL2pp::Rect m_bounding_box;
};
