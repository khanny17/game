#include "chunk.hpp"
#include "util/config.hpp"
#include "view/graphics.hpp"
#include "model/tile.hpp"
#include <SDL2pp/Texture.hh>

using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using SDL2pp::Texture;
using Configuration::config;

Chunk::Chunk(Texture &tileset, Vector2 chunk_pos) :
    m_tiles(),
    m_tileset(tileset),
    m_chunk_pos(chunk_pos),
    m_objects()
{
    for(int x = 0; x < config->CHUNK_SIZE; ++x) {
        for(int y = 0; y < config->CHUNK_SIZE; ++y) {
            Vector2 position = chunk_pos * config->CHUNK_PX_SIZE;
            position.x += x * config->TILE_SIZE * config->SPRITE_SCALE; 
            position.y += y * config->TILE_SIZE * config->SPRITE_SCALE;
            m_tiles.emplace_back(new Tile(m_tileset, Vector2{32,32}, Vector2{0,0}, position));
        }
    }
}

void Chunk::add_object(shared_ptr<Object> object)
{
    m_objects.emplace_back(object);
}

const vector<shared_ptr<Object>> &Chunk::objects() const
{
    return m_objects;
}

const vector<unique_ptr<Tile>> &Chunk::tiles() const
{
    return m_tiles;
}

void Chunk::update(float elapsed_time)
{
    for(auto &&tile: m_tiles) {
        tile->update(elapsed_time);
    }
    for(auto &&object: m_objects) {
        object->update(elapsed_time);
    }
}

Vector2 Chunk::get_chunk_pos() const
{
    return m_chunk_pos;
}
