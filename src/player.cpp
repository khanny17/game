#include "player.hpp"
#include "graphics.hpp"

using std::string;

Player::Player(Graphics &graphics, float x, float y, const Config &config) :
    AnimatedSprite(graphics, "content/sprites/MyChar.png", 
                   0, 0, 16, 16, x, y, config, 100),
    m_dx(0),
    m_dy(0),
    m_facing(RIGHT)

{
    graphics.load_image("content/sprites/link.png");

    setup_animations();
    play_animation("RunRight");
}

void Player::setup_animations()
{
    add_animation(1, 0, 0, "IdleLeft", 16, 23, Vector2::zero());
    add_animation(1, 0, 16, "IdleRight", 16, 23, Vector2::zero());
    add_animation(3, 0, 0, "RunLeft", 16, 23, Vector2::zero());
    add_animation(3, 0, 16, "RunRight", 16, 23, Vector2::zero());
}

void Player::animation_done(string /*current_animation*/)
{
}

void Player::move_up()
{
    m_dy = -m_config.WALK_SPEED;
    play_animation("RunUp");
    m_facing = UP;
}

void Player::move_down()
{
    m_dy = m_config.WALK_SPEED;
    play_animation("RunDown");
    m_facing = DOWN;
}

void Player::move_left()
{
    m_dx = -m_config.WALK_SPEED;
    play_animation("RunLeft");
    m_facing = LEFT;
}

void Player::move_right()
{
    m_dx = m_config.WALK_SPEED;
    play_animation("RunRight");
    m_facing = RIGHT;
}

void Player::stop_moving()
{
    m_dx = 0.0f;
    m_dy = 0.0f;
    switch(m_facing) {
        case UP: play_animation("IdleUp"); break;
        case RIGHT: play_animation("IdleRight"); break;
        case LEFT: play_animation("IdleLeft"); break;
        case DOWN: play_animation("IdleDown"); break;
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
