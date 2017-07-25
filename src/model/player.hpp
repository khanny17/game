#pragma once

#include "character.hpp"
#include "util/config.hpp"
#include "util/direction.hpp"
#include <vector>
#include <memory>

class Player : public Character
{
public:
    Player(float x, float y);
    Player(const Player &other) = delete;

    void update(float elapsed_time);

    void move_up();
    void move_down();
    void move_left();
    void move_right();

    Object::Type get_type() const;
};
