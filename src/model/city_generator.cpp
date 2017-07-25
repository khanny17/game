#include "city_generator.hpp"
#include "building.hpp"
#include "chunk.hpp"
#include "util/random.hpp"
#include "util/config.hpp"
#include "npc.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using Configuration::config;

CityGenerator::CityGenerator()
{
}

void CityGenerator::populate(Chunk &chunk)
{
    auto city_center = add_a_city_center(chunk);
    for(int num_buildings = Random::between(5, 10); 
            num_buildings > 0; --num_buildings) {
        add_a_building(chunk, *city_center);
    }
}

shared_ptr<CityCenter> CityGenerator::add_a_city_center(Chunk &chunk)
{
    auto chunk_pos = chunk.get_chunk_pos().to_pixel_units();
    int x = Random::between(0, config->CHUNK_PX_SIZE);
    int y = Random::between(0, config->CHUNK_PX_SIZE);
    Vector2<float> position(chunk_pos.x + x, chunk_pos.y + y);
    auto city_center = make_shared<CityCenter>(position);
    if(!chunk.add_object(city_center)){
        //If we fail to add the city center something has gone wrong
        throw "Shit.";
    }
    return city_center;
}

void CityGenerator::add_a_building(Chunk &chunk, CityCenter &city_center)
{
    //Try a few times to add it. If there's a collision we just
    //try again
    int max_tries = 3;
    while(max_tries > 0)
    {
        auto position = Random::point_within(city_center.get_position(), Vector2<float>(500, 500));
        auto building = make_shared<Building>(position.x, position.y);
        if(chunk.add_object(building))
        {
            cout << "Generated building at " << position << endl;
            spawn_people_in_a_building(building, chunk);
            return;
        }
        //We failed, try again
        --max_tries;
    }
}

void CityGenerator::spawn_people_in_a_building(shared_ptr<Building> building, Chunk &chunk)
{
    auto num_people = Random::between(1, 4);
    for(int i = 0; i < num_people; ++i) {
        auto npc_pos = Random::point_within(building->get_position(), 
                                            Vector2<float>(500, 500));
        auto npc = make_shared<NPC>(npc_pos);
        if(!chunk.add_object(npc)) {
            cout << "Fuck" << endl;
            continue;
        }

        npc->set_home(building);
    }
}
