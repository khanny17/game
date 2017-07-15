#pragma once

class Chunk;
class Graphics;

class ChunkDrawer
{
public:
    static void draw(const Chunk &chunk, Graphics &g);
};
