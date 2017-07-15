#pragma once

#include "model/player.hpp"
#include "model/chunk.hpp"
#include <memory>
#include <unordered_map>
#include "model/pandoras_box.hpp"

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
    void draw();

    Player &get_player() const;
    Vector2<int> get_current_chunk_pos() const;
    const Chunk &get_chunk(Vector2<int> pos) const;
    bool chunk_at(Vector2<int> pos) const;
    std::array<Vector2<int>, 8> get_surrounding_chunk_positions(Vector2<int> given) const;

    std::vector<std::shared_ptr<Object>> collision_check(const Object &object) const;

private:
    /// Maps a coordinate to a chunk
    std::unordered_map<Vector2<int>, std::unique_ptr<Chunk>> m_chunks;

    /// The player!
    std::unique_ptr<Player> m_player;

    SDL2pp::Texture &m_tileset;

    PandorasBox m_pandoras_box;
    
    /// Returns the current chunk the player is in
    std::unique_ptr<Chunk> gen_chunk(Vector2<int> position);
    Chunk &get_current_chunk();

};
