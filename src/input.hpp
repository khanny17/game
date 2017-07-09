#pragma once

#include <map>
#include <SDL2pp/SDL2pp.hh>

class Input
{
public:
    void begin_new_frame();
    void key_up_event(const SDL_Event &event);
    void key_down_event(const SDL_Event &event);

    bool was_key_pressed(SDL_Scancode key);
    bool was_key_released(SDL_Scancode key);
    bool is_key_held(SDL_Scancode key);

private:
    std::map<SDL_Scancode, bool> m_held_keys;
    std::map<SDL_Scancode, bool> m_pressed_keys;
    std::map<SDL_Scancode, bool> m_released_keys;

};

