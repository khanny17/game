#include "vector2.hpp"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(int X, int Y) : x(X), y(Y) {}

Vector2 Vector2::zero()
{
    return Vector2(0, 0);
}

std::ostream& operator <<(std::ostream& os, const Vector2 &vector2) {
    return os << "Vector2(" << vector2.x << "," << vector2.y << ")";
}
