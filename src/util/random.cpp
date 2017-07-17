#include "random.hpp"
#include "vector2.hpp"
#include <cstdlib>

int Random::between(int min, int max)
{
    return rand() % (max-min + 1) + min;
}

Vector2<float> Random::point_within(Vector2<float> point, Vector2<float> distance)
{
    int x = between(point.x, point.x + distance.x);
    int y = between(point.y, point.y + distance.x);
    return Vector2<float>(x, y);
}
