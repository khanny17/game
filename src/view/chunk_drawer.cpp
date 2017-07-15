#include "chunk_drawer.hpp"
#include "model/chunk.hpp"
#include "model/tile.hpp"
#include "model/object.hpp"
#include "graphics.hpp"
#include "object_drawer.hpp"

void ChunkDrawer::draw(const Chunk &chunk, Graphics &g)
{    
    for(auto &&tile: chunk.tiles()) {
        tile->draw(g);
    }
    for(auto &&object: chunk.objects()) {
        ObjectDrawer::draw(*object, g);
    }
}
