#pragma once

#include "poi_generator.hpp"

class CityGenerator : public POIGenerator
{
public:
    void populate(Chunk &chunk, Graphics &graphics);
};
