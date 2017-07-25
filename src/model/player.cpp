#include "player.hpp"

using Configuration::config;

Player::Player(float x, float y) :
    Character(Vector2<float>(x, y), Vector2<float>(16, 16))
{
}

void Player::update(float elapsed_time)
{
    Character::update(elapsed_time);
}

void Player::move_up()
{
    Character::move_up(config->WALK_SPEED);
}

void Player::move_down()
{
    Character::move_down(config->WALK_SPEED);
}

void Player::move_left()
{
    Character::move_left(config->WALK_SPEED);
}

void Player::move_right()
{
    Character::move_right(config->WALK_SPEED);
}

Object::Type Player::get_type() const
{
    return PLAYER;
}
