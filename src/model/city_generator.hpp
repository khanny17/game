#pragma once

#include "poi_generator.hpp"

class Graphics;
class Chunk;

class CityGenerator : public POIGenerator
{
public:
    void populate(Chunk &chunk, Graphics &graphics);
};
