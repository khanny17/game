#include "character_view.hpp"
#include "model/character.hpp"
#include "util/vector2.hpp"
#include "graphics.hpp"

using std::string;
using GraphicsSingleton::graphics;

CharacterView::CharacterView(const Character &character,
                             const string sprite_file) :
    AnimatedSprite(sprite_file, 0, 0, 16, 16, character.get_position(), 50),
    m_character(character)
{
    graphics->load_image(sprite_file);
    setup_animations();
    play_animation("IdleDown");
}

void CharacterView::setup_animations()
{
    add_animation(1, 0, 0,  "IdleDown",  16, 24, Vector2<float>::zero());
    add_animation(1, 0, 24, "IdleLeft",  16, 24, Vector2<float>::zero());
    add_animation(1, 0, 48, "IdleRight", 16, 24, Vector2<float>::zero());
    add_animation(1, 0, 72, "IdleUp",    16, 24, Vector2<float>::zero());

    add_animation(8, 0, 0,  "RunDown",   16, 24, Vector2<float>::zero());
    add_animation(7, 0, 24, "RunLeft",   16, 24, Vector2<float>::zero());
    add_animation(7, 0, 48, "RunRight",  16, 24, Vector2<float>::zero());
    add_animation(8, 0, 72, "RunUp",     16, 24, Vector2<float>::zero());
}

void CharacterView::draw(float elapsed_time)
{
    AnimatedSprite::update(elapsed_time);

    if(m_character.get_velocity() == Vector2<float>::zero()) {
        switch(m_character.get_facing()) {
            case UP:    play_animation("IdleUp"); break;
            case RIGHT: play_animation("IdleRight"); break;
            case LEFT:  play_animation("IdleLeft"); break;
            case DOWN:  play_animation("IdleDown"); break;
        }
    } else {
        switch(m_character.get_facing()) {
            case UP:    play_animation("RunUp"); break;
            case RIGHT: play_animation("RunRight"); break;
            case LEFT:  play_animation("RunLeft"); break;
            case DOWN:  play_animation("RunDown"); break;
        }
    }
    
    AnimatedSprite::draw(m_character.get_position());
}

void CharacterView::animation_done(string /*current_animation*/)
{
}
