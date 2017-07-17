#include <catch.hpp>
#include <fakeit.hpp>
#include "util/config.hpp"
#include "model/chunk.hpp"
#include "util/vector2.hpp"
#include "model/building.hpp"

#include <iostream>
using std::cout;
using std::endl;

using std::shared_ptr;
using std::make_shared;
using SDL2pp::Texture;
using namespace fakeit;
using Configuration::config;

TEST_CASE("Tiles are added properly")
{
    //The value we will set for the chunk size, for testing purposes
    const int CHUNK_SIZE = 10; 
    const int TILE_SIZE = 32; 
    const float SPRITE_SCALE = 2.0f;

    Configuration::init("config/config.ini", [&](auto ptree){
        ptree.put("chunk_size", CHUNK_SIZE);
        ptree.put("tile_size", TILE_SIZE);
        ptree.put("sprite_scale", SPRITE_SCALE);
    });

    Mock<Texture> texture_mock;

    Chunk c(texture_mock.get(), {-1,0});

    auto &tiles = c.tiles();

    for(int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; ++i)
    {
        Vector2<int> expected_position {
            static_cast<int>(static_cast<int>((i / CHUNK_SIZE) * TILE_SIZE * SPRITE_SCALE + c.get_chunk_pos().x * CHUNK_SIZE * TILE_SIZE * SPRITE_SCALE)),
            static_cast<int>((i % CHUNK_SIZE) * TILE_SIZE * SPRITE_SCALE + c.get_chunk_pos().y * CHUNK_SIZE * TILE_SIZE * SPRITE_SCALE)
        };
        REQUIRE(tiles[i]->get_position() == expected_position);
    }

}
