#include "character.hpp"
#include "util/vector2.hpp"

using std::string;
using std::vector;
using std::shared_ptr;

Character::Character(Vector2<float> position, Vector2<float> size) :
    Object(position, size),
    m_dx(0),
    m_dy(0),
    m_facing(RIGHT)
{
}

void Character::update(float elapsed_time)
{
    m_position.x += m_dx * elapsed_time;
    m_position.y += m_dy * elapsed_time;
}

void Character::move_up(float speed)
{
    m_dy = -speed;
}

void Character::move_down(float speed)
{
    m_dy = speed;
}

void Character::move_left(float speed)
{
    m_dx = -speed;
}

void Character::move_right(float speed)
{
    m_dx = speed;
}

void Character::stop_vertical()
{
    m_dy = 0.0f;
}

void Character::stop_horizontal()
{
    m_dx = 0.0f;
}

void Character::calc_direction()
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

void Character::handle_collisions(vector<shared_ptr<Object>> collisions)
{
    for(auto object: collisions){
        auto side = get_collision_side(*object);
        switch(side)
        {
            case LEFT:
                m_position.x = object->get_bounding_box().GetX2() + 1;
                break;
            case RIGHT:
                m_position.x = object->get_position().x - get_bounding_box().GetW();
                break;
            case UP:
                m_position.y = object->get_bounding_box().GetY2() + 1;
                break;
            case DOWN:
                m_position.y = object->get_position().y - get_bounding_box().GetH();
                break;
        }
    }
}

Vector2<float> Character::get_velocity() const
{
    return Vector2<float>(m_dx, m_dy);
}

Direction4 Character::get_facing() const
{
    return m_facing;
}

