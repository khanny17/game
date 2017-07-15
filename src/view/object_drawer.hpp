#pragma once

class Object;
class Graphics;

class ObjectDrawer
{
public:
    static void draw(const Object &object, Graphics &g);
};
