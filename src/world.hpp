#pragma once

#include "vector2.hpp"
#include "chunk.hpp"
#include <memory>
#include <unordered_map>
#include "graphics.hpp"

/**
 * Holds information about the game world
 */
class World
{
public:
    /**
     * Default constructor which creates a new world
     */
    World(Graphics &graphics);
    World(const World &other) = delete;

    void update(float elapsed_time);
    void draw(Graphics &g);

private:
    /// Maps a coordinate to a chunk
    std::unordered_map<Vector2, std::unique_ptr<Chunk>> m_chunks;

    /// Returns the current chunk the player is in
    Chunk &get_current_chunk();
};
