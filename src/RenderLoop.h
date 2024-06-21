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

    sf::RenderWindow window;
    sf::Event event;
    AnimatedSprite* animatedSprite;
    sf::Texture texture;
    sf::Clock clock;
    sf::Time frameTime;
};