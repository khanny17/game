#pragma once

#include "graphics.hpp"
#include <SDL2pp/SDL.hh>
#include "config.hpp"

class Game
{
public:
    /**
     * Construct our "Game" object
     * \param config object that contains global configuration data
     */
    explicit Game(Config &config);

    /**
     * Function that loops forever while game is running
     */
    void game_loop();

private:
    SDL2pp::SDL m_sdl;
    Config &m_config;

    void draw(Graphics &graphics);
    void update(float elapsed_time);
};
