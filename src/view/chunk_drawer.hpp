#pragma once

class Chunk;
class Graphics;

class ChunkDrawer
{
public:
    static void draw(Chunk &chunk, Graphics &g);
};
