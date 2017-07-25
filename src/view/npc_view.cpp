#include "npc_view.hpp"
#include "model/npc.hpp"

NPCView::NPCView(const NPC &npc) :
    CharacterView(npc, "content/sprites/link.png")
{
}
