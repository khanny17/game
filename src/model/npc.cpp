#include "npc.hpp"
#include "util/random.hpp"

#include <iostream>
using std::cout;
using std::endl;

using std::shared_ptr;
using Configuration::config;

NPC::NPC(Vector2<float> position) : 
    Character(position, Vector2<float>(16, 16)),
    m_home()
{
}

void NPC::update(float elapsed_time)
{
    //Randomly decide to move
    if(Random::between(0, 1000) < 1){
        int dir = Random::between(0, 5);
        float speed = config->WALK_SPEED;
        switch(dir) {
            case 0:  move_up(speed); break;
            case 1:  move_left(speed); break;
            case 2:  move_right(speed); break;
            case 3:  move_down(speed); break;
            default: stop_vertical(); stop_horizontal(); break;
        }
    }
    Character::update(elapsed_time);
}

Object::Type NPC::get_type() const
{
    return Type::NPC;
}

void NPC::set_home(shared_ptr<Building> building)
{
    m_home = building;
}

shared_ptr<Building> NPC::get_home()
{
    return m_home;
}
