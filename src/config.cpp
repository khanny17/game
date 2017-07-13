#include "config.hpp"
#include <boost/property_tree/ini_parser.hpp>

namespace Configuration
{
    std::unique_ptr<ConfigObject> config;

    void init(std::string filepath)
    {
        pt::ptree ptree;
        pt::read_ini(filepath, ptree);
        config = std::make_unique<ConfigObject>(ptree);
    }

    void init(std::string filepath, std::function<void(pt::ptree&)> override_fn)
    {
        pt::ptree ptree;
        pt::read_ini(filepath, ptree);
        override_fn(ptree);
        config = std::make_unique<ConfigObject>(ptree);
    }

    ConfigObject::ConfigObject(pt::ptree &ptree) :
        CHUNK_SIZE(ptree.get<int>("chunk_size")),
        SPRITE_SCALE(ptree.get<float>("sprite_scale")),
        SCREEN_HEIGHT(ptree.get<int>("screen_height")),
        SCREEN_WIDTH(ptree.get<int>("screen_width")),
        PLAYER_HEIGHT(ptree.get<int>("player_height")),
        PLAYER_WIDTH(ptree.get<int>("player_width")),
        MAX_FRAME_TIME(ptree.get<int>("max_frame_time")),
        WALK_SPEED(ptree.get<float>("walk_speed")),
        TILE_SIZE(ptree.get<int>("tile_size")),

        CHUNK_PX_SIZE(CHUNK_SIZE * TILE_SIZE * SPRITE_SCALE)
    {
    }
}
