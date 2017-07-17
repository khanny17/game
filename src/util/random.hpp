#pragma once

#include "util/vector2.hpp"

class Random
{
public:
    static int between(int min, int max);
    static Vector2<float> point_within(Vector2<float> point, Vector2<float> distance);
};
