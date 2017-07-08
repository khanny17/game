#include "graphics.hpp"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640, 480, 0, m_window, m_renderer);
    SDL_SetWindowTitle(m_window, "Game");
}

Graphics::~Graphics()
{
}
