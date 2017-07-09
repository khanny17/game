#pragma once

#include "graphics.hpp"
#include "animated_sprite.hpp"
#include "config.hpp"
#include "direction.hpp"

class Player : public AnimatedSprite
{
public:
    Player(Graphics &graphics, float x, float y, const Config &config);
    void draw(Graphics &graphics);
    void update(float elapsed_time);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void stop_horizontal();
    void stop_vertical();
    void calc_direction();

    void animation_done(std::string current_animation);
    void setup_animations();
private:
    float m_dx, m_dy;
    Direction m_facing;
};
