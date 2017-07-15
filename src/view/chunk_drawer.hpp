#pragma once

class Chunk;

class ChunkDrawer
{
public:
    static void draw_background(const Chunk &chunk);
    static void draw_objects(const Chunk &chunk);
};
