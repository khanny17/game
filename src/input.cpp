#include "input.hpp"


void Input::begin_new_frame()
{
    m_pressed_keys.clear();
    m_released_keys.clear();
}

void Input::key_up_event(const SDL_Event &event)
{
    m_released_keys[event.key.keysym.scancode] = true;
    m_held_keys[event.key.keysym.scancode] = false;
}

void Input::key_down_event(const SDL_Event &event)
{
    m_pressed_keys[event.key.keysym.scancode] = true;
    m_held_keys[event.key.keysym.scancode] = true;
}

bool Input::was_key_pressed(SDL_Scancode key)
{
    return m_pressed_keys[key];
}

bool Input::was_key_released(SDL_Scancode key)
{
    return m_released_keys[key];
}

bool Input::is_key_held(SDL_Scancode key)
{
    return m_held_keys[key];
}
