#pragma once

#include "vector2.hpp"
#include "direction.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include "object.hpp"
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
    Chunk(SDL2pp::Texture &texture, Vector2 chunk_pos);
    Chunk(const Chunk &other) = delete;

    void update(float elapsed_time);
    void draw(Graphics &g);

    std::vector<std::unique_ptr<Tile>> &tiles();

    Vector2 get_chunk_pos() const;

    /**
     * Add an object to this chunk, which will now
     * "own" the object
     */
    void add_object(std::shared_ptr<Object> object);

private:
    std::vector<std::unique_ptr<Tile>> m_tiles;
    SDL2pp::Texture &m_tileset;
    /// This chunk's position in the world
    Vector2 m_chunk_pos;
    /// The objects in this chunk
    std::vector<std::shared_ptr<Object>> m_objects;
};