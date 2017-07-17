#include "building.hpp"

#include <iostream>
using std::cout;
using std::endl;

Building::Building(float posX, float posY) :
    Object(Vector2<float>(posX, posY), Vector2<float>(63, 53)),
    m_sprite("content/buildings/housesetx1/house1x1.gif", 0, 0, 
             63, 53, Vector2<float>(posX, posY)),
    m_position(posX, posY)
{
}

void Building::update(float /*elapsed_time*/)
{
}

void Building::draw()
{
    m_sprite.draw(m_position.x, m_position.y);
}
