#include "RenderLoop.h"
#include <iostream>

#define ENGINE_FPS 60

RenderLoop::RenderLoop(unsigned int fps, const TMJParser& tmjParser)
    : m_window(sf::VideoMode(1280, 928), "LOS-SFML"),
      m_frameTime(sf::seconds(1.0f / fps)),
      m_tmjParser(tmjParser) {
    m_engineTime = sf::seconds(1.0f / ENGINE_FPS);
    loadLayerSprites();
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

void RenderLoop::run2() {

    sf::Clock updateClock; // Clock for tracking the update interval
    sf::Clock eventClock;

    while (m_window.isOpen()) {
        if(eventClock.getElapsedTime() >= m_engineTime) {
            m_currentState->handleEvents(&m_window, &m_event);
            eventClock.restart();
        }
        if (updateClock.getElapsedTime() >= m_frameTime) {
            m_currentState->update();
            updateClock.restart(); // Restart the update clock
        }
        m_currentState->render(&m_window);
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
    m_window.clear(sf::Color::Transparent);

    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;  // Use sf::BlendAlpha to handle transparency correctly

    // Draw layer sprites
    for (const auto& sprite : m_layerSprites) {
        m_window.draw(sprite, states);
    }

    for (SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Static) {
            m_window.draw(*obj->getSprite(), states); // Use blend mode for objects as well
        } else {
            m_window.draw(*obj->getAnimatedSprite(), states); // Use blend mode for animated objects as well
        }
    }
    m_window.display();
}

void RenderLoop::loadLayerSprites() {
    m_layerSprites = m_tmjParser.getLayerSprites();
}


void RenderLoop::setState(State* state){m_currentState = state;}
State* RenderLoop::getState(){return m_currentState;}