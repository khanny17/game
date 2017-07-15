#include "city_generator.hpp"
#include "building.hpp"
#include "chunk.hpp"
#include "util/random.hpp"
#include "util/config.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::make_shared;
using Configuration::config;

CityGenerator::CityGenerator()
{
}

void CityGenerator::populate(Chunk &chunk)
{
    for(int num_buildings = Random::between(5, 10); 
            num_buildings > 0; --num_buildings) {
        Vector2<int> chunk_pos = chunk.get_chunk_pos().to_pixel_units();
        int x = Random::between(0, config->CHUNK_PX_SIZE);
        int y = Random::between(0, config->CHUNK_PX_SIZE);
        Vector2<float> position(chunk_pos.x + x, chunk_pos.y + y);
        chunk.add_object(make_shared<Building>(position.x, position.y));
        cout << "Generated building at " << position << endl;
    }
}
