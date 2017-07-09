#include "game.hpp"
#include <algorithm>
#include <SDL2pp/SDL2pp.hh>
#include "config.hpp"
#include "input.hpp"

using std::min;

Game::Game(Config &config) :
    m_sdl(SDL_INIT_EVERYTHING),
    m_config(config)
{
}

void Game::game_loop()
{
    Graphics graphics;
    Input input;
    SDL_Event event{};

    int last_update_time = SDL_GetTicks();

    while(true) {
        input.begin_new_frame();

        if(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.key_down_event(event);
                }
            }
            else if(event.type == SDL_KEYUP) {
                input.key_up_event(event);
            }
            else if(event.type == SDL_QUIT) {
                return;
            }
        }
        if(input.was_key_pressed(SDL_SCANCODE_ESCAPE)){
            return;
        }

        const int current_time_ms = SDL_GetTicks();
        int elapsed_time_ms = current_time_ms - last_update_time;
        update(min(elapsed_time_ms, m_config.MAX_FRAME_TIME));
        last_update_time = current_time_ms;
    }
}

void Game::update(float /*elapsed_time*/)
{

}

void Game::draw(Graphics &/*graphics)*/)
{
}
