#pragma once

#include "vector2.hpp"
#include "direction.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include <memory>
#include <vector>
#include <SDL2pp/Texture.hh>

/**
 * A section of the world
 */
class Chunk
{
public:
    /**
     * Creates a new chunk with no neighbors
     */
    Chunk(SDL2pp::Texture &texture, Vector2 chunk_num);
    Chunk(const Chunk &other) = delete;

    void update(float elapsed_time);
    void draw(Graphics &g);

    std::vector<std::unique_ptr<Tile>> &tiles();

private:
    std::vector<std::unique_ptr<Tile>> m_tiles;
    SDL2pp::Texture &m_tileset;
};
