#pragma once

#include <memory>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>

class Graphics
{
public:
    Graphics();
private:
    SDL2pp::Window m_window;
    SDL2pp::Renderer m_renderer;
};
