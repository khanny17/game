#pragma once

#include "util/vector2.hpp"
#include "util/direction.hpp"
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
    enum Type
    {
        NONE,
        BUILDING,
        PLAYER,
        NPC,
        CITY_CENTER
    };

    Object(Vector2<float> position, Vector2<float> size);
    Object(const Object &other) = delete;

    virtual void update(float elapsed_time) = 0;
    virtual void draw();
    virtual Type get_type() const = 0;
    Vector2<float> get_position() const;
    SDL2pp::Rect get_bounding_box() const;
    bool collides_with(const Object &other) const;
    Direction4 get_collision_side(const Object &other) const;

    unsigned long long get_id() const;

protected:
    Vector2<float> m_position;
    Vector2<float> m_size;

private:
    static unsigned long long NEXT_ID;
    const unsigned long long m_id;
};
