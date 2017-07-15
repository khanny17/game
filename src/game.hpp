#pragma once

#include "model/world.hpp"
#include <memory>
#include <SDL2pp/SDL.hh>

class WorldView;

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

    void draw(WorldView &world_view, float elapsed_time);
    void update(float elapsed_time);
    std::unique_ptr<World> build_world(SDL2pp::Texture &tileset);

    std::unique_ptr<World> m_world;
};
