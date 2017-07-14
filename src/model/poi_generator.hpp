#pragma once

#include "chunk.hpp"

class POIGenerator
{
public:
    virtual void populate(Chunk &chunk, Graphics &graphics) = 0;
};
