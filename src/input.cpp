#include "input.hpp"

using std::move;
using std::map;
using std::vector;
using std::unique_ptr;

void Input::begin_new_frame()
{
    m_pressed_keys.clear();
    m_released_keys.clear();
}

Receipt &Input::on_key_up(SDL_Scancode key, CallbackType callback)
{
    return register_callback(key, move(callback), m_key_up_watchers);
}

Receipt &Input::on_key_down(SDL_Scancode key, CallbackType callback)
{
    return register_callback(key, move(callback), m_key_down_watchers);
}

Receipt &Input::while_key_held(SDL_Scancode key, CallbackType callback)
{
    return register_callback(key, move(callback), m_key_held_watchers);
}

Receipt &Input::register_callback(SDL_Scancode key, CallbackType callback, 
        map<SDL_Scancode, vector<unique_ptr<Receipt>>> &group)
{
    auto receipt = new Receipt(move(callback));
    group[key].emplace_back(receipt);
    return *receipt; 
}

void Input::key_up_event(const SDL_Event &event)
{
    //Update everyone who was watching for this key to be released
    for(auto &&receipt: m_key_up_watchers[event.key.keysym.scancode]) {
        receipt->callback(); 
    }
    m_released_keys[event.key.keysym.scancode] = true;
    m_held_keys[event.key.keysym.scancode] = false;
}

void Input::key_down_event(const SDL_Event &event)
{
    //Update everyone who was watching for this key to be pressed
    for(auto &&receipt: m_key_down_watchers[event.key.keysym.scancode]) {
        receipt->callback(); 
    }
    m_pressed_keys[event.key.keysym.scancode] = true;
    m_held_keys[event.key.keysym.scancode] = true;
}

void Input::process_held_key_callbacks()
{
    //For every key that is held down
    for(auto entry: m_held_keys) {
        auto key = entry.first;
        auto key_held = entry.second;
        //If key not pressed, do nothing
        if(!key_held) {
            continue;
        }

        //Call every callback watching to see if this key is held
        for(auto &&receipt: m_key_held_watchers[key]){
            receipt->callback();
        }
    }
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
