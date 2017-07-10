#include "sprite.hpp"

using std::string;
using SDL2pp::Rect;
using Configuration::config;

Sprite::Sprite(Graphics &graphics, const string &file_path, 
               int sourceX, int sourceY, int width, int height,
               float posX, float posY) :
    m_source_rect(sourceX, sourceY, width, height),
    m_sprite_sheet(graphics.get_renderer(), graphics.load_image(file_path)),
    m_x(posX),
    m_y(posY)
{}

Sprite::~Sprite() = default;

void Sprite::draw(Graphics &graphics, int x, int y)
{
    Rect destRect(x, y, m_source_rect.w * config.get<int>("sprite_scale"), 
                  m_source_rect.h * config.get<int>("sprite_scale"));
    graphics.blit_surface(m_sprite_sheet, m_source_rect, destRect);
}

void Sprite::update() {}

Vector2 Sprite::get_position() const
{
    return Vector2(m_x, m_y);
}
