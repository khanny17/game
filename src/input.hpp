#pragma once

#include <map>
#include <memory>
#include <functional>
#include <SDL2pp/SDL2pp.hh>

typedef std::function<void()> CallbackType;

struct Receipt
{
    bool disabled;
    CallbackType callback;
    Receipt(CallbackType cb, bool disabled = false) :
        disabled(disabled),
        callback(cb) {}
    Receipt(const Receipt &other) = delete;
};

typedef std::map<SDL_Scancode, std::vector<std::unique_ptr<Receipt>>> CbMapType;

class Input
{
public:
    void begin_new_frame();
    void key_up_event(const SDL_Event &event);
    void key_down_event(const SDL_Event &event);

    bool was_key_pressed(SDL_Scancode key);
    bool was_key_released(SDL_Scancode key);
    bool is_key_held(SDL_Scancode key);

    /**
     * Register a callback for when the given key is pressed
     * Returns a handle to their callback, so they can 
     * disable it if they want
     */
    Receipt &on_key_up(SDL_Scancode key, CallbackType callback);
    Receipt &on_key_down(SDL_Scancode key, CallbackType callback);
    Receipt &while_key_held(SDL_Scancode key, CallbackType callback);

    /**
     * Call once per update cycle to update anyone watching for a held key
     */
    void process_held_key_callbacks();

private:
    std::map<SDL_Scancode, bool> m_held_keys;
    std::map<SDL_Scancode, bool> m_pressed_keys;
    std::map<SDL_Scancode, bool> m_released_keys;

    CbMapType m_key_up_watchers;
    CbMapType m_key_down_watchers;
    CbMapType m_key_held_watchers;

    Receipt &register_callback(SDL_Scancode key, CallbackType callback,
                               CbMapType &group);

};

