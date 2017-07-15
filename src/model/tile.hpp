#pragma once

#include <SDL2pp/Texture.hh>
#include <memory>
#include "view/graphics.hpp"
#include "util/vector2.hpp"
#include "util/config.hpp"

class Tile
{
public:

    Tile(SDL2pp::Texture &tileset, Vector2<int> size, Vector2<int> tileset_position,
         Vector2<int> position);

    void update(int elapsed_time);
    void draw();

    Vector2<int> get_position();
private:
    SDL2pp::Texture &m_tileset;
    Vector2<int> m_size;
    Vector2<int> m_tileset_position;
    Vector2<int> m_position;
};
