#include "RenderLoop.h"
#include <iostream>

RenderLoop::RenderLoop(unsigned int fps)
    : m_window(sf::VideoMode(800, 600), "Empty black box."),
      m_frameTime(sf::seconds(1.0f / fps)) {
    // Texture goes here just as an example.
    if (!m_texture.loadFromFile("res/sprite_config/sprite.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    m_animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", m_texture);
}

RenderLoop::~RenderLoop() {
    delete m_animatedSprite;
}

void RenderLoop::run() {
    while (m_window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void RenderLoop::handleEvents() {
    while (m_window.pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void RenderLoop::update() {
    m_animatedSprite->incrementFrame();
}

void RenderLoop::render() {
    m_window.clear();
    m_window.draw(*m_animatedSprite);
    m_window.display();
    sf::sleep(m_frameTime - m_clock.getElapsedTime());
    m_clock.restart();
}