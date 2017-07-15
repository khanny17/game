#include "player_view.hpp"
#include "animated_sprite.hpp"
#include "model/player.hpp"
#include "util/vector2.hpp"
#include "graphics.hpp"

#include <iostream>
using std::cout;
using std::endl;

using std::string;
using GraphicsSingleton::graphics;

PlayerView::PlayerView(const Player &player) :
    AnimatedSprite("content/sprites/link.png", 
             0, 0, 16, 16, player.get_position(), 50),
    m_player(player)
{
    graphics->load_image("content/sprites/link.png");
    setup_animations();
    play_animation("IdleDown");
}

void PlayerView::setup_animations()
{
    add_animation(1, 0, 0,  "IdleDown",  16, 24, Vector2<float>::zero());
    add_animation(1, 0, 24, "IdleLeft",  16, 24, Vector2<float>::zero());
    add_animation(1, 0, 48, "IdleRight", 16, 24, Vector2<float>::zero());
    add_animation(1, 0, 72, "IdleUp",    16, 24, Vector2<float>::zero());

    add_animation(8, 0, 0,  "RunDown",   16, 24, Vector2<float>::zero());
    add_animation(7, 0, 24, "RunLeft",   16, 24, Vector2<float>::zero());
    add_animation(7, 0, 48, "RunRight",  16, 24, Vector2<float>::zero());
    add_animation(8, 0, 72, "RunUp",     16, 24, Vector2<float>::zero());
}

void PlayerView::animation_done(string /*current_animation*/)
{
}

void PlayerView::draw(float elapsed_time)
{
    AnimatedSprite::update(elapsed_time);

    if(m_player.get_velocity() == Vector2<float>::zero()) {
        switch(m_player.get_facing()) {
            case UP:    play_animation("IdleUp"); break;
            case RIGHT: play_animation("IdleRight"); break;
            case LEFT:  play_animation("IdleLeft"); break;
            case DOWN:  play_animation("IdleDown"); break;
        }
    } else {
        switch(m_player.get_facing()) {
            case UP:    play_animation("RunUp"); break;
            case RIGHT: play_animation("RunRight"); break;
            case LEFT:  play_animation("RunLeft"); break;
            case DOWN:  play_animation("RunDown"); break;
        }
    }
    
    AnimatedSprite::draw(m_player.get_position());
}
