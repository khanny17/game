#include "graphics.hpp"
#include <SDL2pp/SDL2pp.hh>

Graphics::Graphics() :
    m_window("Game", 
             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
             640, 480, 
             SDL_WINDOW_RESIZABLE),
    m_renderer(m_window, -1, SDL_RENDERER_ACCELERATED)
{
}
