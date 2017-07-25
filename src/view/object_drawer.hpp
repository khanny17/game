#pragma once

#include <memory>
#include <unordered_map>
#include "npc_view.hpp"

class Object;

class ObjectDrawer
{
public:
    static void draw(const Object &object, float elapsed_time);

    static std::unordered_map<unsigned long long, std::shared_ptr<NPCView>> npc_views;
};
