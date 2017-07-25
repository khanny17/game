#pragma once

#include <string>
#include "character_view.hpp"

class Player;

class PlayerView : public CharacterView
{
public:
    explicit PlayerView(const Player &player);
private:
    const Player &m_player;
};
