#include "tile.hpp"

#include <SDL2pp/Rect.hh>

using SDL2pp::Texture;
using SDL2pp::Rect;
using Configuration::config;

Tile::Tile(Texture &tileset, Vector2 size, Vector2 tileset_position,
           Vector2 position) :
    m_tileset(tileset),
    m_size(size),
    m_tileset_position(tileset_position),
    m_position(Vector2(position.x, position.y))
{
}

void Tile::update(int /*elapsed_time*/)
{
}

void Tile::draw(Graphics &graphics)
{
    Rect dest_rect(m_position.x, m_position.y,
                   m_size.x * config->SPRITE_SCALE,
                   m_size.y * config->SPRITE_SCALE);
    
    Rect source_rect(m_tileset_position.x, m_tileset_position.y,
                     m_size.x, m_size.y);

    graphics.blit_surface(m_tileset, source_rect, dest_rect);
}
    
Vector2 Tile::get_position()
{
    return m_position;
}
