#pragma once

#include "model/player.hpp"
#include "model/chunk.hpp"
#include <memory>
#include <unordered_map>
#include "view/graphics.hpp"
#include "model/pandoras_box.hpp"

class Vector2;

/**
 * Holds information about the game world
 */
class World
{
public:
    /**
     * Default constructor which creates a new world
     */
    World(std::unique_ptr<Player> player, SDL2pp::Texture &tileset, Graphics &graphics);
    World(const World &other) = delete;

    void update(float elapsed_time);
    void draw(Graphics &g);

    Player &get_player() const;
    Vector2 get_current_chunk_pos() const;
    const Chunk &get_chunk(Vector2 pos) const;
    bool chunk_at(Vector2 pos) const;
    std::array<Vector2, 8> get_surrounding_chunk_positions(Vector2 given) const;

private:
    /// Maps a coordinate to a chunk
    std::unordered_map<Vector2, std::unique_ptr<Chunk>> m_chunks;

    /// The player!
    std::unique_ptr<Player> m_player;

    SDL2pp::Texture &m_tileset;

    PandorasBox m_pandoras_box;
    
    Graphics &m_graphics;

    /// Returns the current chunk the player is in
    std::unique_ptr<Chunk> gen_chunk(Vector2 position);
    Chunk &get_current_chunk();

};
