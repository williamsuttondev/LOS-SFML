#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "TMJParser.h"
#include "SceneObject.h"

class RenderLoop {
public:
    RenderLoop(unsigned int fps, const TMJParser& tmjParser);
    ~RenderLoop();
    
    std::vector<SceneObject*>& getSceneObjects();
    void addObject(SceneObject* obj);
    void run();

private:
    void handleEvents();
    void update();
    void render();
    void loadLayerSprites();

    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Time m_frameTime;
    sf::Time m_engineTime;

    const TMJParser& m_tmjParser;
    std::vector<SceneObject*> m_sceneObjects;
    std::vector<sf::Sprite> m_layerSprites;
};
