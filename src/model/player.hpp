#pragma once

#include "object.hpp"
#include "util/config.hpp"
#include "util/direction.hpp"
#include <vector>
#include <memory>

class Player : public Object
{
public:
    Player(float x, float y);
    Player(const Player &other) = delete;

    void draw();
    void update(float elapsed_time);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void stop_horizontal();
    void stop_vertical();
    void calc_direction();
    void handle_collisions(std::vector<std::shared_ptr<Object>> collisions);

    Vector2<float> get_velocity() const;
    Direction4 get_facing() const;

private:
    float m_dx, m_dy;
    Direction4 m_facing;
};
