#pragma once

#include "chunk.hpp"

class POIGenerator
{
public:
    virtual void populate(Chunk &chunk) = 0;
};
