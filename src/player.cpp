#include "player.hpp"
#include "graphics.hpp"

using std::string;
using Configuration::config;

Player::Player(Graphics &graphics, float x, float y) :
    AnimatedSprite(graphics, "content/sprites/link.png", 
                   0, 0, 16, 16, x, y, 50),
    m_dx(0),
    m_dy(0),
    m_facing(RIGHT)
{
    graphics.load_image("content/sprites/link.png");

    setup_animations();
    play_animation("IdleDown");
}

void Player::setup_animations()
{
    add_animation(1, 0, 0,  "IdleDown",  16, 24, Vector2::zero());
    add_animation(1, 0, 24, "IdleLeft",  16, 24, Vector2::zero());
    add_animation(1, 0, 48, "IdleRight", 16, 24, Vector2::zero());
    add_animation(1, 0, 72, "IdleUp",    16, 24, Vector2::zero());

    add_animation(8, 0, 0,  "RunDown",   16, 24, Vector2::zero());
    add_animation(7, 0, 24, "RunLeft",   16, 24, Vector2::zero());
    add_animation(7, 0, 48, "RunRight",  16, 24, Vector2::zero());
    add_animation(8, 0, 72, "RunUp",     16, 24, Vector2::zero());
}

void Player::animation_done(string /*current_animation*/)
{
}

void Player::move_up()
{
    m_dy = -config->WALK_SPEED;
}

void Player::move_down()
{
    m_dy = config->WALK_SPEED;
}

void Player::move_left()
{
    m_dx = -config->WALK_SPEED;
}

void Player::move_right()
{
    m_dx = config->WALK_SPEED;
}

void Player::stop_vertical()
{
    m_dy = 0.0f;
}

void Player::stop_horizontal()
{
    m_dx = 0.0f;
}

void Player::calc_direction()
{
    if(m_dy < 0.0f) {
        m_facing = UP;
        play_animation("RunUp");
        return;
    }

    if(m_dy > 0.0f) {
        m_facing = DOWN;
        play_animation("RunDown");
        return;
    }

    if(m_dx < 0.0f) {
        m_facing = LEFT;
        play_animation("RunLeft");
        return;
    }

    if(m_dx > 0.0f) {
        m_facing = RIGHT;
        play_animation("RunRight");
        return;
    }
    
    //If we get here, it implies that we aren't moving at all
    switch(m_facing) {
        case UP:    play_animation("IdleUp"); break;
        case RIGHT: play_animation("IdleRight"); break;
        case LEFT:  play_animation("IdleLeft"); break;
        case DOWN:  play_animation("IdleDown"); break;
    }
}

void Player::update(float elapsed_time)
{
    m_x += m_dx * elapsed_time;
    m_y += m_dy * elapsed_time;

    AnimatedSprite::update(elapsed_time);
}

void Player::draw(Graphics &graphics)
{
    AnimatedSprite::draw(graphics, m_x, m_y);
}
