#pragma once

class Config
{
public:
    const int FPS = 60;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const float SPRITE_SCALE = 2.0f;

    const float WALK_SPEED = 0.2f;

    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
};