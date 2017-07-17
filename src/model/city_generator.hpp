#pragma once

#include "poi_generator.hpp"
#include "city_center.hpp"
#include <memory>

class Chunk;

class CityGenerator : public POIGenerator
{
public:
    CityGenerator();
    void populate(Chunk &chunk);
private:
    void add_a_building(Chunk &chunk, CityCenter &city_center);
    std::shared_ptr<CityCenter> add_a_city_center(Chunk &chunk);
};
