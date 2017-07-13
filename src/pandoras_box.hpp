#pragma once

#include "poi_generator.hpp"
#include "city_generator.hpp"

/**
 * This class is responsible for randomly selecting a generator to use
 * to populate a chunk with things. 
 */
class PandorasBox
{
public:
    PandorasBox();

    /**
     * Randomly select a POI Generator
     */
    POIGenerator &pick_poi_generator();

private:
    CityGenerator m_city_generator;
};
