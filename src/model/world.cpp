#include "world.hpp"
#include "util/vector2.hpp"
#include <algorithm>

using std::move;
using std::array;
using std::shared_ptr;
using std::unique_ptr;
using std::make_unique;
using std::out_of_range;
using std::vector;
using SDL2pp::Texture;
using Configuration::config;

World::World(unique_ptr<Player> player, Texture &tileset) :
    m_chunks(),
    m_player(move(player)),
    m_tileset(tileset),
    m_pandoras_box()
{
    m_chunks[{0,0}] = gen_chunk({0,0});
}

unique_ptr<Chunk> World::gen_chunk(Vector2<int> position)
{
    auto new_chunk = make_unique<Chunk>(m_tileset, position);
    m_pandoras_box.pick_poi_generator().populate(*new_chunk);
    return new_chunk;
}

Player &World::get_player() const
{
    return *m_player;
}

Chunk &World::get_current_chunk()
{
    auto chunk_id = get_current_chunk_pos();
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

Vector2<int> World::get_current_chunk_pos() const
{
    Vector2<int> chunk_id = Vector2<float>::to_int_v(m_player->get_position() / config->CHUNK_PX_SIZE);
    //If negative, we need to subtract one, for reasons you see if you calc it
    if(m_player->get_position().x < 0) {
        chunk_id.x -= 1;
    }

    if(m_player->get_position().y < 0) {
        chunk_id.y -= 1;
    }
    return chunk_id;
}

const Chunk &World::get_chunk(Vector2<int> pos) const
{
    return *m_chunks.at(pos);
}

bool World::chunk_at(Vector2<int> pos) const
{
    return m_chunks.find(pos) != m_chunks.end();
}

array<Vector2<int>, 8> World::get_surrounding_chunk_positions(Vector2<int> given) const
{
    return {{
        Vector2<int>(given.x - 1, given.y - 1),  
        Vector2<int>(given.x - 1, given.y),  
        Vector2<int>(given.x - 1, given.y + 1),  
        Vector2<int>(given.x,     given.y - 1),  
        Vector2<int>(given.x,     given.y + 1),  
        Vector2<int>(given.x + 1, given.y - 1),  
        Vector2<int>(given.x + 1, given.y),  
        Vector2<int>(given.x + 1, given.y + 1)
    }};
}

vector<shared_ptr<Object>> World::collision_check(const Object &object) const
{
    //Find the chunk the object is in
    auto chunk_pos = Vector2<float>::to_int_v(object.get_position() / config->CHUNK_PX_SIZE);
    vector<shared_ptr<Object>> collisions = get_chunk(chunk_pos).check_collisions(object);

    //Check if there are collisions in objects in surrounding chunks
    for(auto neighbor_pos: get_surrounding_chunk_positions(chunk_pos)){
        auto more = get_chunk(neighbor_pos).check_collisions(object);
        collisions.reserve(collisions.size() + more.size()); //hopefully speeds up insertion
        collisions.insert(collisions.end(), more.begin(), more.end());
    }

    return collisions;
}

void World::update(float elapsed_time)
{
    m_player->update(elapsed_time);
    auto &cur_chunk = get_current_chunk();
    cur_chunk.update(elapsed_time);
    auto surrounding_chunks = get_surrounding_chunk_positions(cur_chunk.get_chunk_pos());
    for(auto chunk_pos: surrounding_chunks){
        if(m_chunks.find(chunk_pos) == m_chunks.end()) {
            m_chunks[chunk_pos] = gen_chunk(chunk_pos);
        }
        m_chunks[chunk_pos]->update(elapsed_time);
    }

    //Handle collisions
    auto collisions = collision_check(*m_player);
    if(!collisions.empty()){
        m_player->handle_collisions(collisions);
    }
}
