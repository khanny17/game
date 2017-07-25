#pragma once

#include "object.hpp"

/**
 * Common functionality for characters that move
 * around, like the player or an npc
 */
class Character : public Object
{
public:
    Character(Vector2<float> position, Vector2<float> size);

    virtual void update(float elapsed_time);

    virtual Object::Type get_type() const = 0;

    void move_up(float speed);
    void move_down(float speed);
    void move_left(float speed);
    void move_right(float speed);
    void stop_vertical();
    void stop_horizontal();
    void calc_direction();

    void handle_collisions(std::vector<std::shared_ptr<Object>> collisions);

    Vector2<float> get_velocity() const;
    Direction4 get_facing() const;

private:
    float m_dx, m_dy;
    Direction4 m_facing;
};
