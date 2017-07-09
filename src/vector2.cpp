#include "vector2.hpp"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(int X, int Y) : x(X), y(Y) {}

Vector2 Vector2::zero()
{
    return Vector2(0, 0);
}
