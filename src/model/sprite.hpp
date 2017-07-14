#pragma once

#include <string>
#include <SDL2pp/SDL2pp.hh>
#include "util/config.hpp"
#include "util/vector2.hpp"

class Graphics;

class Sprite
{
public:
    Sprite(Graphics &graphics, const std::string &file_path, 
           int sourceX, int sourceY, int width, int height,
           float posX, float posY);
    virtual ~Sprite();
    virtual void update(float elapsed_time);
    void draw(Graphics &graphics, int x, int y);
    Vector2 get_position() const;

protected:
    SDL2pp::Rect m_source_rect;
    SDL2pp::Texture m_sprite_sheet;
    float m_x;
    float m_y;
};
