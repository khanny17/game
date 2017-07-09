#include "sprite.hpp"

using std::string;
using SDL2pp::Rect;

Sprite::Sprite(Graphics &graphics, const string &file_path, 
               int sourceX, int sourceY, int width, int height,
               float posX, float posY,
               const Config &config) :
    m_source_rect(sourceX, sourceY, width, height),
    m_sprite_sheet(graphics.get_renderer(), *graphics.load_image(file_path).get()),
    m_x(posX),
    m_y(posY),
    m_config(config)
{

}

Sprite::~Sprite() = default;

void Sprite::draw(Graphics &graphics, int x, int y)
{
    Rect destRect(x, y, m_source_rect.w * m_config.SPRITE_SCALE, 
                  m_source_rect.h * m_config.SPRITE_SCALE);
    graphics.blit_surface(m_sprite_sheet, m_source_rect, destRect);
}

void Sprite::update() {}
