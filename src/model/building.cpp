#include "building.hpp"

Building::Building(Graphics &graphics, float posX, float posY) :
    Object(Vector2(posX, posY)), 
    m_sprite(graphics, "content/buildings/housesetx1/house1x1.gif", 0, 0, 
             32, 32, posX, posY),
    m_position(posX, posY)
{
}
            

void Building::update(float /*elapsed_time*/)
{
}

void Building::draw(Graphics &g)
{
    m_sprite.draw(g, m_position.x, m_position.y);
}
