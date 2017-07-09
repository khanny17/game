#include "graphics.hpp"
#include <SDL2pp/SDL2pp.hh>

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Rect;
using std::shared_ptr;
using std::make_shared;

Graphics::Graphics() :
    m_window("Game", 
             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
             640, 480, 
             SDL_WINDOW_RESIZABLE),
    m_renderer(m_window, -1, SDL_RENDERER_ACCELERATED)
{
}

shared_ptr<Surface> Graphics::load_image(const std::string &file_path)
{
    if(m_sprite_sheets.find(file_path) == m_sprite_sheets.end()) {
        //If it doesnt already exist, load it
        m_sprite_sheets.emplace(file_path, make_shared<Surface>(file_path));
    }
    return m_sprite_sheets[file_path];
}

void Graphics::blit_surface(Texture &texture, Rect &sourceRect, Rect &destRect)
{
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
