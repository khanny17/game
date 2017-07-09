#include <iostream>
#include <SDL2pp/SDL2pp.hh>
#include "game.hpp"

int main(/* int argc, char **argv */)
{
    Config config{};
    Game game(config);
    game.game_loop();
    return 0;
}
