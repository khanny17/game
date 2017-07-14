#include <iostream>
#include <SDL2pp/SDL2pp.hh>
#include "game.hpp"
#include "util/config.hpp"

int main(/* int argc, char **argv */)
{
    Configuration::init("config/config.ini");
    Game game;
    game.game_loop();
    return 0;
}
