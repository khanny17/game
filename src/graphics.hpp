#pragma once

#include <memory>
#include <SDL2/SDL.h>

class Graphics
{
public:
    Graphics();
    ~Graphics();
private:
    std::unique_ptr<SDL_Window> m_window;
    std::unique_ptr<SDL_Renderer> m_renderer;
};
