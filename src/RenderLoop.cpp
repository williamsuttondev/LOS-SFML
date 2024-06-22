#include "RenderLoop.h"
#include <iostream>

RenderLoop::RenderLoop(unsigned int fps)
    : m_window(sf::VideoMode(800, 600), "LOS-SFML"),
      m_frameTime(sf::seconds(1.0f / fps)) {
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
    while (m_window.isOpen()) {
        handleEvents();
        update();
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
    sf::sleep(m_frameTime - m_clock.getElapsedTime());
    m_clock.restart();
}