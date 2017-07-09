#include "level.hpp"

using std::move;
using std::string;
using SDL2pp::Rect;
using SDL2pp::Texture;

Level::Level(string map_name, Vector2 spawn_point, Graphics &graphics, 
             const Config &config):
    m_map_name(map_name),
    m_spawn_point(spawn_point),
    m_size(0,0),
    m_background_texture(graphics.get_renderer(), 
                         graphics.load_image("content/backgrounds/bkBlue.png")),
    m_config(config)
{
    load_map(map_name, graphics);
}

void Level::load_map(string map_name, Graphics &graphics) 
{
    m_map_name = move(map_name);
    m_size = Vector2(1280, 960);
    m_background_texture = Texture(graphics.get_renderer(), 
                        graphics.load_image("content/backgrounds/bkBlue.png"));
}

void Level::update(int /*elapsed_time*/)
{
}

void Level::draw(Graphics &graphics)
{
    Rect sourceRect(0, 0, 64, 64);
    for(int x = 0; x < m_size.x / 64; ++x) {
        for(int y = 0; y < m_size.y / 64; ++y) {
            Rect destRect(x * 64 * m_config.SPRITE_SCALE, 
                          y * 64 * m_config.SPRITE_SCALE, 
                          64 * m_config.SPRITE_SCALE, 
                          64 * m_config.SPRITE_SCALE);
            graphics.blit_surface(m_background_texture, sourceRect, destRect);
        }
    }
}
