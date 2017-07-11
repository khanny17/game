#pragma once

#include <SDL2pp/Texture.hh>
#include <memory>
#include "graphics.hpp"
#include "vector2.hpp"
#include "config.hpp"

class Tile
{
public:

    Tile(SDL2pp::Texture &tileset, Vector2 size, Vector2 tileset_position,
         Vector2 position);

    void update(int elapsed_time);
    void draw(Graphics &graphics);

    Vector2 get_position();
private:
    SDL2pp::Texture &m_tileset;
    Vector2 m_size;
    Vector2 m_tileset_position;
    Vector2 m_position;
};
