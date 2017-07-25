#pragma once

#include "character.hpp"
#include <memory>

class Building;

class NPC : public Character
{
public:
    NPC(Vector2<float> position);
    NPC(const NPC &other) = delete;

    void update(float elapsed_time);
    Object::Type get_type() const;

    void set_home(std::shared_ptr<Building> building);
    std::shared_ptr<Building> get_home();

private:
    std::shared_ptr<Building> m_home;
};
