#include "chunk_drawer.hpp"
#include "model/chunk.hpp"
#include "model/tile.hpp"
#include "model/object.hpp"
#include "graphics.hpp"
#include "object_drawer.hpp"

void ChunkDrawer::draw_background(const Chunk &chunk)
{    
    for(auto &&tile: chunk.tiles()) {
        tile->draw();
    }
}

void ChunkDrawer::draw_objects(const Chunk &chunk, float elapsed_time)
{    
    for(auto &&object: chunk.objects()) {
        ObjectDrawer::draw(*object, elapsed_time);
    }
}
