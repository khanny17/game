#include "chunk.hpp"
#include <SDL2pp/Texture.hh>

using std::vector;
using std::unique_ptr;
using SDL2pp::Texture;
using Configuration::config;

Chunk::Chunk(Texture &tileset, Vector2 chunk_pos) :
    m_tiles(),
    m_tileset(tileset),
    m_chunk_pos(chunk_pos)
{
    static auto tile_size    = config.get<int>("tile_size");
    static auto sprite_scale = config.get<float>("sprite_scale");
    static auto chunk_size   = config.get<int>("chunk_size");
    static auto chunk_px_size = chunk_size * tile_size * sprite_scale;
    for(int x = 0; x < config.get<int>("chunk_size"); ++x) {
        for(int y = 0; y < config.get<int>("chunk_size"); ++y) {
            Vector2 position = chunk_pos * chunk_px_size;
            position.x += x * tile_size * sprite_scale; 
            position.y += y * tile_size * sprite_scale;
            m_tiles.emplace_back(new Tile(m_tileset, Vector2{32,32}, Vector2{0,0}, position));
        }
    }
}

vector<unique_ptr<Tile>> &Chunk::tiles()
{
    return m_tiles;
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

Vector2 Chunk::get_chunk_pos() const
{
    return m_chunk_pos;
}
