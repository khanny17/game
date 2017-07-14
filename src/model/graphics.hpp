#pragma once

#include <string>
#include <map>
#include <memory>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/Surface.hh>
#include "config.hpp"

class Graphics
{
public:
    Graphics();
    Graphics(const Graphics &other) = delete;

    /**
     * Loads an image into the sprite_sheets map if it doesn't already exist
     */
    SDL2pp::Surface &load_image(const std::string &file_path);

    /**
     * Draws a texture to a certain part of the screen
     */
    void blit_surface(SDL2pp::Texture &texture,
            SDL2pp::Rect &sourceRect,
            SDL2pp::Rect &destRect);

    /**
     * Renders everything to the screen
     */
    void flip();

    /**
     * Clears the screen
     */
    void clear();

    /**
     * Move the camera's position to center on the given coords
     */
    void center_camera(int x, int y, int w, int h);

    SDL2pp::Renderer &get_renderer();

private:
    SDL2pp::Window m_window;
    SDL2pp::Renderer m_renderer;
    SDL2pp::Rect m_camera;

    std::map<std::string, std::unique_ptr<SDL2pp::Surface>> m_sprite_sheets;
};
