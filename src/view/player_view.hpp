#pragma once

#include <string>
#include "animated_sprite.hpp"

class Player;

class PlayerView : public AnimatedSprite
{
public:
    explicit PlayerView(const Player &player);

    void draw(float elapsed_time);
    void setup_animations();
    void animation_done(std::string current_animation);
private:
    const Player &m_player;
};
