#include "world.hpp"

using std::move;
using std::shared_ptr;
using std::unique_ptr;
using std::make_unique;
using SDL2pp::Texture;

World::World(unique_ptr<Player> player, Texture &tileset) :
    m_chunks(),
    m_player(move(player)),
    m_tileset(tileset)
{
    m_chunks[{0,0}] = gen_chunk(Vector2{0,0});
}

unique_ptr<Chunk> World::gen_chunk(Vector2 position)
{
    return make_unique<Chunk>(m_tileset, position);
}

Player &World::get_player() const
{
    return *m_player;
}

Chunk &World::get_current_chunk()
{
    return *m_chunks.at({0,0}); //TODO calc based on player coords
}

void World::update(float elapsed_time)
{
    m_player->update(elapsed_time);
    auto &cur_chunk = get_current_chunk();
    cur_chunk.update(elapsed_time);
}

void World::draw(Graphics &g)
{
    auto &cur_chunk = get_current_chunk();
    cur_chunk.draw(g);
    m_player->draw(g);
}
