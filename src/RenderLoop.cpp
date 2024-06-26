#include "RenderLoop.h"
#include <iostream>

#define ENGINE_FPS 60

RenderLoop::RenderLoop(unsigned int fps)
    : m_window(sf::VideoMode(1280, 720), "LOS-SFML"),
      m_frameTime(sf::seconds(1.0f / fps)) {
        m_engineTime = sf::seconds(1.0f / ENGINE_FPS);
    }

RenderLoop::~RenderLoop() {
    for (SceneObject* obj : m_sceneObjects) {
        delete obj;
    }
}

std::vector<SceneObject*>& RenderLoop::getSceneObjects() {
    return this->m_sceneObjects;
}

void RenderLoop::addObject(SceneObject* obj) {
    m_sceneObjects.push_back(obj);
}

void RenderLoop::run() {
    sf::Clock updateClock; // Clock for tracking the update interval
    sf::Clock eventClock;
    while (m_window.isOpen()) {
        if(eventClock.getElapsedTime() >= m_engineTime) {
            handleEvents();
            eventClock.restart();
        }
        if (updateClock.getElapsedTime() >= m_frameTime) {
            update();
            updateClock.restart(); // Restart the update clock
        }
        render();
    }
}

void RenderLoop::handleEvents() {
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            default:
                break;
        }
    }

    for (SceneObject* obj : m_sceneObjects) {
        if(obj->isPlayerControlled()) {
            obj->cllCtrlFunction();
        }
    }
}

void RenderLoop::update() {
    for(SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Animated) {
            obj->getAnimatedSprite()->incrementFrame();
        }
    }
}

void RenderLoop::render() {
    m_window.clear();
    for (SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Static) {
            m_window.draw(*obj->getSprite());
        } else {
            m_window.draw(*obj->getAnimatedSprite());
        }
    }
    m_window.display();
    //sf::sleep(m_frameTime - m_clock.getElapsedTime());
    //m_clock.restart();
}