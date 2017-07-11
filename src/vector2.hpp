#pragma once

#include <functional>
#include <sstream>

class Vector2
{
public:
    Vector2();
    Vector2(int X, int Y);

    static Vector2 zero();

    int x;
    int y;

    bool operator==(const Vector2 &other) const
    { 
        return x == other.x && y == other.y;
    }

    Vector2 operator*(int scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    friend std::ostream& operator<< (std::ostream& stream, const Vector2& matrix);
};

namespace std
{
    template <>
    struct hash<Vector2>
    {
        size_t operator()(const Vector2 &v) const
        {
            stringstream ss;
            ss << v.x << "," << v.y;
            return hash<string>()(ss.str());
        }
    };
}
