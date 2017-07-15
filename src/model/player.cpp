#include "player.hpp"
#include "view/graphics.hpp"
#include "util/vector2.hpp"
#include <iostream>

using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;
using Configuration::config;

Player::Player(float x, float y) :
    Object(Vector2<float>(x, y), Vector2<float>(16, 16)),
    m_dx(0),
    m_dy(0),
    m_facing(RIGHT)
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
        return;
    }

    if(m_dy > 0.0f) {
        m_facing = DOWN;
        return;
    }

    if(m_dx < 0.0f) {
        m_facing = LEFT;
        return;
    }

    if(m_dx > 0.0f) {
        m_facing = RIGHT;
        return;
    }
}

void Player::update(float elapsed_time)
{
    m_position.x += m_dx * elapsed_time;
    m_position.y += m_dy * elapsed_time;
}

void Player::handle_collisions(vector<shared_ptr<Object>> collisions)
{
    for(auto object: collisions){
        cout << object->get_position() << endl;
    }
}

Vector2<float> Player::get_velocity() const
{
    return Vector2<float>(m_dx, m_dy);
}

Direction4 Player::get_facing() const
{
    return m_facing;
}
