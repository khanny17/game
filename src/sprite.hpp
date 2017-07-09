#pragma once

#include <string>
#include <SDL2pp/SDL2pp.hh>
#include "graphics.hpp"

class Sprite
{
public:
    Sprite(Graphics &graphics, const std::string &file_path, 
           int sourceX, int sourceY, int width, int height,
           float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);

private:
    SDL2pp::Rect m_source_rect;
    SDL2pp::Texture m_sprite_sheet;

    float m_x;
    float m_y;
};
