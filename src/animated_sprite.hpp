#pragma once

#include "sprite.hpp"
#include "graphics.hpp"
#include "config.hpp"
#include "vector2.hpp"
#include <string>
#include <memory>
#include <vector>
#include <SDL2pp/Rect.hh>

class AnimatedSprite : public Sprite 
{
public:
    AnimatedSprite(Graphics &graphics, const std::string &file_path,
                   int sourceX, int sourceY, int width, int height,
                   float posX, float posY, float time_to_update);

    void play_animation(const std::string &animation, bool once = false);

    void update(float elapsed_time);

    void draw(Graphics &graphics, int x, int y);

protected:
    double m_time_to_update;
    bool m_current_animation_once;
    std::string m_current_animation;

    void add_animation(int frames, int x, int y, std::string name, 
                      int width, int height, Vector2 offset);

    void reset_animations();

    void stop_animation();

    void set_visible(bool visible);

    virtual void animation_done(std::string current_animation);

    ///TOOD consider putting into constructor and removing this one
    virtual void setup_animations() = 0;

private:
    std::map<std::string, std::vector<std::shared_ptr<SDL2pp::Rect>>> m_animations;
    std::map<std::string, Vector2> m_offsets;

    unsigned int m_frame_index;
    double m_time_elapsed;
    bool m_visible;
};
