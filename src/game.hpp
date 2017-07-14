#pragma once

#include "model/world.hpp"
#include <memory>
#include <SDL2pp/SDL.hh>

class Graphics;

namespace SDL2pp 
{
    class Texture;
}

class Game
{
public:
    /**
     * Construct our "Game" object
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
    std::unique_ptr<World> build_world(Graphics &graphics, SDL2pp::Texture &tileset);

    std::unique_ptr<World> m_world;
};
