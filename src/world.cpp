#include "world.hpp"

using std::make_unique;

World::World(Graphics &graphics) :
    m_chunks(),
    m_tileset(graphics.get_renderer(), 
              graphics.load_image("content/backgrounds/bkBlue.png"))
{
    m_chunks[{0,0}] = make_unique<Chunk>(m_tileset, Vector2{0,0});
}

Chunk &World::get_current_chunk()
{
    return *m_chunks.at({0,0}); //TODO calc based on player coords
}

void World::update(float elapsed_time)
{
    auto &cur_chunk = get_current_chunk();
    cur_chunk.update(elapsed_time);
}

void World::draw(Graphics &g)
{
    auto &cur_chunk = get_current_chunk();
    cur_chunk.draw(g);
}
