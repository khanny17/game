#pragma once

#include "config.hpp"
#include <functional>
#include <sstream>

template<typename T>
class Vector2
{
public:
    Vector2() : x(0), y(0) {}
    Vector2(T X, T Y) : x(X), y(Y) {}

    static Vector2 zero()
    {
        return Vector2(0, 0);
    }

    T x;
    T y;

    static Vector2<int> to_int_v(Vector2 original)
    {
        return Vector2<int>(static_cast<int>(original.x),
                            static_cast<int>(original.y));
    }

    Vector2 to_pixel_units() const 
    {
        return *this * Configuration::config->CHUNK_PX_SIZE;
    }

    bool operator==(const Vector2 &other) const
    { 
        return x == other.x && y == other.y;
    }

    Vector2 operator*(T scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 operator/(T scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    friend std::ostream& operator<< (std::ostream& os, const Vector2& v)
    {
        return os << "Vector2(" << v.x << "," << v.y << ")";
    }
};

namespace std
{
    template<typename T>
    struct hash<Vector2<T>>
    {
        size_t operator()(const Vector2<T> &v) const
        {
            stringstream ss;
            ss << v.x << "," << v.y;
            return hash<string>()(ss.str());
        }
    };
}
