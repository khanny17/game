#pragma once

#include "graphics.hpp"
#include "input.hpp"
#include <memory>
#include <SDL2pp/SDL.hh>
#include "config.hpp"
#include "player.hpp"
#include "world.hpp"

class Game
{
public:
    /**
     * Construct our "Game" object
     * \param config object that contains global configuration data
     */
    Game();

    /**
     * Function that loops forever while game is running
     */
    void game_loop();

private:
    SDL2pp::SDL m_sdl;

    void draw(Graphics &graphics);
    void update(float elapsed_time);

    std::unique_ptr<Player> m_player;
    std::unique_ptr<World> m_world;
};
