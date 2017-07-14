#pragma once

#include "view/graphics.hpp"

/**
 * This is really a placeholder, I haven't put thought into
 * design for the things that will exist in the world besides
 * the chunks and tiles. In general though this is atm the 
 * root level class for a thing that shows up on the screen
 */
class Object
{
public:
    virtual void update(float elapsed_time) = 0;
};
