#include "object_drawer.hpp"
#include "model/object.hpp"
#include "graphics.hpp"
#include "sprite.hpp"
#include "model/building.hpp"
#include "model/npc.hpp"
#include "npc_view.hpp"

using std::make_shared;

std::unordered_map<unsigned long long, std::shared_ptr<NPCView>> ObjectDrawer::npc_views;

void ObjectDrawer::draw(const Object &object, float elapsed_time)
{
    if(object.get_type() != Object::Type::NPC) {
        const_cast<Object&>(object).draw();
        return;
    }

    if(npc_views.find(object.get_id()) == npc_views.end()) {
        npc_views[object.get_id()] = make_shared<NPCView>(static_cast<const NPC&>(object));
    }

    npc_views[object.get_id()]->draw(elapsed_time);
}
