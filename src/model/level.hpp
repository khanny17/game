#pragma once

#include "util/vector2.hpp"
#include "view/graphics.hpp"
#include <string>
#include <SDL2pp/Texture.hh>

class Level
{
public:
    Level(std::string map_name, Vector2 spawn_point, Graphics &graphics);
    void update(int elapsed_time);
    void draw(Graphics &graphics);

private:
    std::string m_map_name;
    Vector2 m_spawn_point;
    Vector2 m_size;
    SDL2pp::Texture m_background_texture;

    void load_map(std::string map_name, Graphics &graphics);
};
