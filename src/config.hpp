#pragma once

class Config
{
public:
    const int FPS = 60;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 480;

    const float SPRITE_SCALE = 2.0f;

    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
};
