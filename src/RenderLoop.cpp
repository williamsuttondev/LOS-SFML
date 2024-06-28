#include "RenderLoop.h"
#include <iostream>

#define ENGINE_FPS 60

RenderLoop::RenderLoop(unsigned int fps, const TMJParser& tmjParser)
    : m_window(sf::VideoMode(1280, 928), "LOS-SFML"),
      m_frameTime(sf::seconds(1.0f / fps)),
      m_tmjParser(tmjParser) {
    m_engineTime = sf::seconds(1.0f / ENGINE_FPS);
    loadLayerTextures();
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

    // Draw layer sprites
    for (const auto& sprite : m_layerSprites) {
        m_window.draw(sprite);
    }

    for (SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Static) {
            m_window.draw(*obj->getSprite());
        } else {
            m_window.draw(*obj->getAnimatedSprite());
        }
    }
    m_window.display();
}
void RenderLoop::loadLayerTextures() {
    const auto& layerImages = m_tmjParser.getLayerImages();
    for (const auto& image : layerImages) {
        sf::Texture texture;
        if (!texture.loadFromImage(image)) {
            throw std::runtime_error("Unable to load texture from image");
        }
        m_layerTextures.push_back(texture);

        sf::Sprite sprite;
        sprite.setTexture(m_layerTextures.back());
        m_layerSprites.push_back(sprite);
    }
}