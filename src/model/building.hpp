#pragma once

#include "object.hpp"
#include "view/graphics.hpp"
#include "sprite.hpp"

class Building : public Object
{
public:
    Building(Graphics &graphics, float posX, float posY);
    void update(float elapsed_time);
    void draw(Graphics &g);

private:
    Sprite m_sprite;
    Vector2 m_position;
};
