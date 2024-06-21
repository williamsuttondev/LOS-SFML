#include "RenderLoop.h"
#include <iostream>

RenderLoop::RenderLoop(unsigned int fps)
    : window(sf::VideoMode(800, 600), "Empty black box."),
      frameTime(sf::seconds(1.0f / fps)) {
    sf::Texture texture;
    // Texture goes here just as an example.
    if (!texture.loadFromFile("res/sprite_config/texture.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
}

RenderLoop::~RenderLoop() {
    delete animatedSprite;
}

void RenderLoop::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void RenderLoop::handleEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void RenderLoop::update() {
    animatedSprite->incrementFrame();
}

void RenderLoop::render() {
    window.clear();
    window.display();
    sf::sleep(frameTime - clock.getElapsedTime());
    clock.restart();
}