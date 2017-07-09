#pragma once

#include "graphics.hpp"
#include <memory>
#include <SDL2pp/SDL.hh>
#include "config.hpp"
#include "player.hpp"
#include "level.hpp"

class Game
{
public:
    /**
     * Construct our "Game" object
     * \param config object that contains global configuration data
     */
    explicit Game(const Config &config);

    /**
     * Function that loops forever while game is running
     */
    void game_loop();

private:
    SDL2pp::SDL m_sdl;
    const Config &m_config;

    void draw(Graphics &graphics);
    void update(float elapsed_time);

    std::unique_ptr<Player> m_player;
    std::unique_ptr<Level> m_level;
};
