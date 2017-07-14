#pragma once

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace Configuration
{
    class ConfigObject
    {
    public:
        ConfigObject(pt::ptree &ptree);
        
        const int CHUNK_SIZE;
        const float SPRITE_SCALE;
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
        const int PLAYER_HEIGHT;
        const int PLAYER_WIDTH;
        const int MAX_FRAME_TIME;
        const float WALK_SPEED;
        const int TILE_SIZE;
        const int CHUNK_PX_SIZE;
    };

    extern std::unique_ptr<ConfigObject> config;
    void init(std::string filepath);
    /// Specify a lambda so the caller can actually edit the ptree as need be
    void init(std::string filepath, std::function<void(pt::ptree&)> override_fn);
}


