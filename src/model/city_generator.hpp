#pragma once

#include "poi_generator.hpp"

class Chunk;

class CityGenerator : public POIGenerator
{
public:
    CityGenerator();
    void populate(Chunk &chunk);
};
