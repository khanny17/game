#pragma once

class World;
class Graphics;

/**
 * Draw the world
 */
class WorldView
{
public:
    WorldView(const World &world);

    void draw(Graphics &g);

private:
    const World &m_world;
};
