#pragma once
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class RenderLoop {
public:
    RenderLoop(unsigned int fps);
    ~RenderLoop();
    void run();

private:
    void handleEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    sf::Event m_event;
    AnimatedSprite* m_animatedSprite;
    sf::Texture m_texture;
    sf::Clock m_clock;
    sf::Time m_frameTime;
};