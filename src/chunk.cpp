#include "chunk.hpp"
#include <SDL2pp/Texture.hh>

using SDL2pp::Texture;
using Configuration::config;

Chunk::Chunk(Graphics &graphics, Vector2 chunk_num) :
    m_tiles(),
    m_tileset(graphics.get_renderer(), 
              graphics.load_image("content/backgrounds/bkBlue.png"))
{
    for(int x = 0; x < config.get<int>("chunk_size"); ++x) {
        for(int y = 0; y < config.get<int>("chunk_size"); ++y) {
            Vector2 position = chunk_num * config.get<int>("chunk_size");
            position.x += x; position.y += y;
            m_tiles.emplace_back(new Tile(m_tileset, Vector2{32,32}, Vector2{0,0}, position));
        }
    }
}

void Chunk::update(float elapsed_time)
{
    for(auto &&tile: m_tiles) {
        tile->update(elapsed_time);
    }
}

void Chunk::draw(Graphics &g)
{
    for(auto &&tile: m_tiles) {
        tile->draw(g);
    }
}
