#pragma once

#include "character_view.hpp"

class NPC;

class NPCView : public CharacterView
{
public:
    NPCView(const NPC &npc);
};
