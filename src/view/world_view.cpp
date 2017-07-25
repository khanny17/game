#include "world_view.hpp"
#include "model/world.hpp"
#include "view/graphics.hpp"
#include "view/chunk_drawer.hpp"

using std::array;

WorldView::WorldView(const World &world) :
    m_world(world),
    m_player_view(world.get_player())
{
}

void WorldView::draw(float elapsed_time)
{
    auto &cur_chunk = m_world.get_chunk(m_world.get_current_chunk_pos());
    auto neighbors = m_world.get_surrounding_chunk_positions(cur_chunk.get_chunk_pos());
    draw_background(cur_chunk, neighbors);
    draw_objects(cur_chunk, neighbors, elapsed_time);

    m_player_view.draw(elapsed_time);
}

void WorldView::draw_background(const Chunk &cur, array<Vector2<int>, 8> neighbors)
{
    ChunkDrawer::draw_background(cur);
    for(auto chunk_pos: neighbors) {
        if(m_world.chunk_at(chunk_pos)) {
            ChunkDrawer::draw_background(m_world.get_chunk(chunk_pos));
        }
    }
}

void WorldView::draw_objects (const Chunk &cur,
                              array<Vector2<int>, 8> neighbors, 
                              float elapsed_time)
{
    ChunkDrawer::draw_objects(cur, elapsed_time);
    for(auto chunk_pos: neighbors) {
        if(m_world.chunk_at(chunk_pos)) {
            ChunkDrawer::draw_objects(m_world.get_chunk(chunk_pos), elapsed_time);
        }
    }
}
