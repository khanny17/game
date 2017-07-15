#include "world_view.hpp"
#include "model/world.hpp"
#include "view/graphics.hpp"
#include "view/chunk_drawer.hpp"

WorldView::WorldView(const World &world) :
    m_world(world)
{
}

void WorldView::draw(Graphics &g)
{
    auto &cur_chunk = m_world.get_chunk(m_world.get_current_chunk_pos());
    ChunkDrawer::draw(cur_chunk, g);
    for(auto chunk_pos: m_world.get_surrounding_chunk_positions(cur_chunk.get_chunk_pos())){
        if(m_world.chunk_at(chunk_pos)) {
            ChunkDrawer::draw(m_world.get_chunk(m_world.get_current_chunk_pos()), g);
        }
    }
    m_world.get_player().draw(g);
}
