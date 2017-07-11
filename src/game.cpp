#include "game.hpp"
#include "config.hpp"
#include "input.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <algorithm>

using std::min;
using std::move;
using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using Configuration::config;
using SDL2pp::Texture;

Game::Game() :
    m_sdl(SDL_INIT_EVERYTHING),
    m_world()
{
}

unique_ptr<World> Game::build_world(Graphics &graphics, Texture &tileset)
{
    auto player = make_unique<Player>(graphics, 0, 0);
    auto world = make_unique<World>(move(player), tileset);
    return world;
}

void Game::game_loop()
{
    Graphics graphics;
    Texture tileset(graphics.get_renderer(),
			    	graphics.load_image("content/backgrounds/bkBlue.png"));
    Input input;
    SDL_Event event{};
    bool keep_running = true;

    m_world = build_world(graphics, tileset);
    auto &player = m_world->get_player();

    //Close when they press escape
    input.on_key_down(SDL_SCANCODE_ESCAPE, [&keep_running](){
        keep_running = false;
    });

    int last_update_time = SDL_GetTicks();
    while(keep_running) {
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

        input.process_held_key_callbacks();

        if(input.is_key_held(SDL_SCANCODE_LEFT)){
            player.move_left();
        } else if(input.is_key_held(SDL_SCANCODE_RIGHT)) {
            player.move_right();
        } else {
            player.stop_horizontal();
        }

        if(input.is_key_held(SDL_SCANCODE_UP)){
            player.move_up();
        } else if(input.is_key_held(SDL_SCANCODE_DOWN)) {
            player.move_down();
        } else {
            player.stop_vertical();
        }

        player.calc_direction();

        auto player_pos = player.get_position();
        graphics.center_camera(player_pos.x, player_pos.y,
                               config.get<int>("player_width"),
                               config.get<int>("player_height"));

        const int current_time_ms = SDL_GetTicks();
        int elapsed_time_ms = current_time_ms - last_update_time;
        update(min(elapsed_time_ms, config.get<int>("max_frame_time")));
        last_update_time = current_time_ms;

        draw(graphics);
    }
}

void Game::update(float elapsed_time)
{
    m_world->update(elapsed_time);
}

void Game::draw(Graphics &graphics)
{
    graphics.clear();
    m_world->draw(graphics);
    graphics.flip();
}
