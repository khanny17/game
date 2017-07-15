#pragma once

#include "poi_generator.hpp"

class Chunk;

class NothingGenerator : public POIGenerator
{
public:
    void populate(Chunk &chunk);
};
