#include "object_drawer.hpp"
#include "model/object.hpp"
#include "graphics.hpp"
#include "sprite.hpp"

void ObjectDrawer::draw(const Object &object)
{
    Sprite sprite("content/buildings/housesetx1/house1x1.gif",
                  0, 0, 64, 64, {0,0});
    Vector2<float> pos = object.get_position();
    sprite.draw(pos.x, pos.y);
}
