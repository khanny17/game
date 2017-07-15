#include "object_drawer.hpp"
#include "model/object.hpp"
#include "graphics.hpp"

void ObjectDrawer::draw(const Object &object, Graphics &g)
{
    Sprite sprite(g, "content/buildings/housesetx1/house1x1.gif",
                  0, 0, 64, 64, 0, 0);
    Vector2 pos = object.get_position();
    sprite.draw(g, pos.x, pos.y);
}
