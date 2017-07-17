#pragma once

#include "object.hpp"

class CityCenter : public Object
{
public:
    explicit CityCenter(Vector2<float> position);
    void update(float);
};
