#pragma once

class Vector2
{
public:
    Vector2();
    Vector2(int X, int Y);

    static Vector2 zero();

    int x;
    int y;
};
