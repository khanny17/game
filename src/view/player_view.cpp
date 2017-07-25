#include "player_view.hpp"
#include "model/player.hpp"

#include <iostream>
using std::cout;
using std::endl;

PlayerView::PlayerView(const Player &player) :
    CharacterView(player, "content/sprites/link.png"),
    m_player(player)
{
}
