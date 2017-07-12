#pragma once

#include "vector2.hpp"
#include "player.hpp"
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
    World(std::unique_ptr<Player> player, SDL2pp::Texture &tileset);
    World(const World &other) = delete;

    void update(float elapsed_time);
    void draw(Graphics &g);

    Player &get_player() const;

private:
    const int CHUNK_PX_SIZE;
    /// Maps a coordinate to a chunk
    std::unordered_map<Vector2, std::unique_ptr<Chunk>> m_chunks;

    /// The player!
    std::unique_ptr<Player> m_player;

    SDL2pp::Texture &m_tileset;

    /// Returns the current chunk the player is in
    Chunk &get_current_chunk();
    std::unique_ptr<Chunk> gen_chunk(Vector2 position);

    std::array<Vector2, 8> get_surrounding_chunk_positions(Vector2 given);
};
