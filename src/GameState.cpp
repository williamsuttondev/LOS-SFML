#include "GameState.h"
#include <iostream>

void GameState::handleEvents(){}

void GameState::handleEvents(sf::RenderWindow* window, sf::Event* event){
    // std::cout << "m_sceneObjects.size() " << m_sceneObjects.size() << std::endl;
    while (window->pollEvent(*event)) {
        switch (event->type) {
            case sf::Event::Closed:
                window->close();
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

void GameState::update(){
    for(SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Animated) {
            obj->getAnimatedSprite()->incrementFrame();
        }
    }
}

void GameState::render(){}

void GameState::render(sf::RenderWindow* window){
    window->clear(sf::Color::Transparent);

    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;  // Use sf::BlendAlpha to handle transparency correctly

    // Draw layer sprites
    for (const auto& sprite : m_layerSprites) {
        window->draw(sprite, states);
    }

    for (SceneObject* obj : m_sceneObjects) {
        if(obj->getType() == SceneObject::Type::Static) {
            window->draw(*obj->getSprite(), states); // Use blend mode for objects as well
        } else {
            window->draw(*obj->getAnimatedSprite(), states); // Use blend mode for animated objects as well
        }
    }
    window->display();
}

void GameState::changeState(){}
void GameState::changeState(State* state){}
void GameState::cleanUp(){} 

std::vector<SceneObject*> GameState::getSceneObjects(){return m_sceneObjects;} 

std::vector<sf::Sprite> GameState::getLayerSprites(){return m_layerSprites;} 

void GameState::setSceneObjects(std::vector<SceneObject*> sceneObjects){m_sceneObjects = sceneObjects;} 

void GameState::setLayerSprites(std::vector<sf::Sprite> layerSprites){m_layerSprites = layerSprites; } 

void GameState::loadLayerSprites(TMJParser tmjParser)
{
    m_layerSprites = tmjParser.getLayerSprites();
}

void GameState::addObject(SceneObject* obj) {
    m_sceneObjects.push_back(obj);
}
