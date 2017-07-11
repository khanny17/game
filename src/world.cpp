#include "world.hpp"

using std::move;
using std::shared_ptr;
using std::unique_ptr;
using std::make_unique;
using std::out_of_range;
using SDL2pp::Texture;
using Configuration::config;

World::World(unique_ptr<Player> player, Texture &tileset) :
    CHUNK_PX_SIZE(config.get<int>("chunk_size") * 
                  config.get<int>("tile_size") *
                  config.get<float>("sprite_scale")),
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
    Vector2 chunk_id = m_player->get_position() / CHUNK_PX_SIZE;
    //If negative, we need to subtract one, for reasons you see if you calc it
    if(m_player->get_position().x < 0) {
        chunk_id.x -= 1;
    }

    if(m_player->get_position().y < 0) {
        chunk_id.y -= 1;
    }

    try 
    {
        return *m_chunks.at(chunk_id);
    }
    catch(out_of_range)
    {
        m_chunks[chunk_id] = gen_chunk(chunk_id);
        return *m_chunks.at(chunk_id);
    }

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
