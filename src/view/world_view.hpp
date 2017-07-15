#pragma once

#include <array>
#include "player_view.hpp"
#include "util/vector2.hpp"

class World;
class Chunk;

/**
 * Draw the world
 */
class WorldView
{
public:
    WorldView(const World &world);

    void draw(float elapsed_time);

private:
    const World &m_world;
    PlayerView m_player_view;

    void draw_background(const Chunk &cur, std::array<Vector2<int>, 8> neighbors);
    void draw_objects(const Chunk &cur, std::array<Vector2<int>, 8> neighbors);
};
