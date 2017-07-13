#include "city_generator.hpp"
#include "building.hpp"
#include "graphics.hpp"

using std::make_shared;

void CityGenerator::populate(Chunk &chunk, Graphics &graphics)
{
    Vector2 position = chunk.get_chunk_pos().to_pixel_units();
    chunk.add_object(make_shared<Building>(graphics, position.x, position.y));
}
