#include "vector2.hpp"
#include "config.hpp"

using Configuration::config;

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(int X, int Y) : x(X), y(Y) {}

Vector2 Vector2::zero()
{
    return Vector2(0, 0);
}

//Converts a vector in chunk units to pixel units
//If you are at chunk 1, 1, and a chunk is 10x10 tiles,
//and a tile is 32 px, and its scaled by 2, the top left corner
//is 1*10*32*2 = 640px by 640px
Vector2 Vector2::to_pixel_units() const
{
    return *this * config->CHUNK_PX_SIZE;
}

std::ostream& operator <<(std::ostream& os, const Vector2 &vector2) {
    return os << "Vector2(" << vector2.x << "," << vector2.y << ")";
}
