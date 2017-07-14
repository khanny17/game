#include <iostream>
#include <SDL2pp/SDL2pp.hh>
#include "model/game.hpp"

int main(/* int argc, char **argv */)
{
    Configuration::init("config/config.ini");
    Game game;
    game.game_loop();
    return 0;
}
