#pragma once

#include <string>
#include "animated_sprite.hpp"

class Character;

class CharacterView : public AnimatedSprite
{
public:
    explicit CharacterView(const Character &character,
                           const std::string sprite_file);

    virtual void draw(float elapsed_time);
    virtual void setup_animations();
    virtual void animation_done(std::string current_animation);
private:
    const Character &m_character;
};

