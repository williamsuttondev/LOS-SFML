#pragma once
#include "AnimatedSprite.h"
#include "SceneObject.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "TMJParser.h"

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
    
    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Time m_frameTime;
    sf::Time m_engineTime;
    sf::Clock m_clock;
    std::vector<SceneObject*> m_sceneObjects;
    
    const TMJParser& m_tmjParser;
    std::vector<sf::Texture> m_layerTextures;
    std::vector<sf::Sprite> m_layerSprites;

    void loadLayerTextures();
};