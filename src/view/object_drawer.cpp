#include "object_drawer.hpp"
#include "model/object.hpp"
#include "graphics.hpp"
#include "sprite.hpp"
#include "model/building.hpp"

void ObjectDrawer::draw(const Object &object)
{
    const_cast<Building&>(static_cast<const Building&>(object)).draw();
}
