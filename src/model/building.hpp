#pragma once

#include "object.hpp"
#include "view/graphics.hpp"
#include "view/sprite.hpp"
#include "util/vector2.hpp"

class Building : public Object
{
public:
    Building(float posX, float posY);
    void update(float elapsed_time);
    void draw();

private:
    Sprite m_sprite;
    Vector2<float> m_position;
};
