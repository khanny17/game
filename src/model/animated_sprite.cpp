#include "animated_sprite.hpp"
#include "view/graphics.hpp"

using std::string;
using std::vector;
using std::shared_ptr;
using SDL2pp::Rect;
using Configuration::config;

AnimatedSprite::AnimatedSprite(Graphics &graphics, const string &file_path,
                               int sourceX, int sourceY, int width, int height,
                               float posX, float posY, float time_to_update) :
    Sprite(graphics, file_path, sourceX, sourceY, width, height, posX, posY),
    m_time_to_update(time_to_update),
    m_current_animation_once(false),
    m_current_animation(""),
    m_frame_index(0),
    m_time_elapsed(0),
    m_visible(true)
{}

void AnimatedSprite::add_animation(int frames, int x, int y, string name,
                                  int width, int height, Vector2 offset)
{
    m_animations.emplace(name, vector<shared_ptr<Rect>>{});
    auto &rectangles = m_animations.at(name);
    for(int i = 0; i < frames; ++i)
    {
        rectangles.emplace_back(new Rect((i + x) * width, y, width, height));
    }

    m_offsets.emplace(name, offset);
}

void AnimatedSprite::reset_animations()
{
    m_animations.clear();
    m_offsets.clear();
}

void AnimatedSprite::play_animation(const string &animation, bool once)
{
    m_current_animation_once = once;
    if(m_current_animation != animation) {
        m_current_animation = animation;
        m_frame_index = 0;
    }
}

void AnimatedSprite::set_visible(bool visible)
{
    m_visible = visible;
}
void AnimatedSprite::stop_animation()
{
    m_frame_index = 0;
    animation_done(m_current_animation);
}

void AnimatedSprite::update(float elapsed_time)
{
    Sprite::update(elapsed_time);

    m_time_elapsed += elapsed_time;
    if(m_time_elapsed <= m_time_to_update) {
        return;
    }

    m_time_elapsed -= m_time_to_update;

    if(m_frame_index < m_animations.at(m_current_animation).size() - 1) {
        ++m_frame_index;
    } else {
        if(m_current_animation_once) {
            set_visible(false);
        }
        m_frame_index = 0;
        animation_done(m_current_animation);
    }
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y) {
    if(!m_visible) {
        return;
    }

    auto offset = m_offsets.at(m_current_animation);

    Rect destRect(x + offset.x,
                  y + offset.y, 
                  m_source_rect.w * config->SPRITE_SCALE,
                  m_source_rect.h * config->SPRITE_SCALE);

    Rect sourceRect = *m_animations.at(m_current_animation)[m_frame_index].get();
    graphics.blit_surface(m_sprite_sheet, sourceRect, destRect);
}

void AnimatedSprite::animation_done(string /*current_animation*/)
{
}
