#pragma once

#include <string>
#include <SDL2pp/SDL2pp.hh>
#include "util/config.hpp"
#include "util/vector2.hpp"

class Sprite
{
public:
    Sprite(const std::string &file_path, 
           int sourceX, int sourceY, int width, int height,
           Vector2<float> position);
    virtual ~Sprite();
    virtual void update(float elapsed_time);
    void draw(int x, int y);

protected:
    SDL2pp::Rect m_source_rect;
    SDL2pp::Texture m_sprite_sheet;
    Vector2<float> m_position;
};
