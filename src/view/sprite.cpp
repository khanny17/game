#include "sprite.hpp"
#include "view/graphics.hpp"

using std::string;
using SDL2pp::Rect;
using Configuration::config;
using GraphicsSingleton::graphics;

Sprite::Sprite(const string &file_path, 
               int sourceX, int sourceY, int width, int height,
               Vector2<float> position) :
    m_source_rect(sourceX, sourceY, width, height),
    m_sprite_sheet(graphics->get_renderer(), graphics->load_image(file_path)),
    m_position(position)
{}

Sprite::~Sprite() = default;

void Sprite::draw(int x, int y)
{
    Rect destRect(x, y, m_source_rect.w * config->SPRITE_SCALE, 
                  m_source_rect.h * config->SPRITE_SCALE);
    graphics->blit_surface(m_sprite_sheet, m_source_rect, destRect);
}

void Sprite::update(float /*elapsed_time*/) {}
