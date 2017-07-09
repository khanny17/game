#include "graphics.hpp"
#include "config.hpp"
#include <SDL2pp/SDL2pp.hh>

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Rect;
using std::make_unique;

Graphics::Graphics(const Config &config) :
    m_window("Game", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            config.SCREEN_WIDTH, config.SCREEN_HEIGHT, 
            SDL_WINDOW_RESIZABLE),
    m_renderer(m_window, -1, SDL_RENDERER_ACCELERATED),
    m_camera(0, 0, config.SCREEN_WIDTH, config.SCREEN_HEIGHT),
    m_config(config)
{
}

Surface &Graphics::load_image(const std::string &file_path)
{
    if(m_sprite_sheets.find(file_path) == m_sprite_sheets.end()) {
        //If it doesnt already exist, load it
        m_sprite_sheets.emplace(file_path, make_unique<Surface>(file_path));
    }
    return *m_sprite_sheets[file_path];
}

void Graphics::center_camera(int x, int y, int w, int h)
{
    m_camera.x = ( x + (w * m_config.SPRITE_SCALE) / 2 ) - m_config.SCREEN_WIDTH / 2;
    m_camera.y = ( y + (h * m_config.SPRITE_SCALE) / 2 ) - m_config.SCREEN_HEIGHT / 2;
}

void Graphics::blit_surface(Texture &texture, Rect &sourceRect, Rect &destRect)
{
    destRect.x -= m_camera.x;
    destRect.y -= m_camera.y;
    m_renderer.Copy(texture, sourceRect, destRect);
}

void Graphics::flip()
{
    m_renderer.Present();
}

void Graphics::clear()
{
    m_renderer.Clear();
}

Renderer &Graphics::get_renderer()
{
    return m_renderer;
}
