#include "State.h"
#include <iostream>

void State::handleEvents(){}

void State::handleEvents( sf::RenderWindow* window, sf::Event* event){}

void State::update(){}

void State::update(void (*func)()){}
void State::update(void (*func)(float)){}
void State::update(void (*func)(float,float)){}


void State::render(){}

void State::render(sf::RenderWindow* window){}


void State::changeState(){}
void State::changeState(State* state){}
void State::cleanUp(){}


std::vector<SceneObject*> State::getSceneObjects(){
  
    return m_sceneObjects;
}

std::vector<sf::Sprite> State::getLayerSprites(){
    
    return m_layerSprites;
}

void State::setSceneObjects(std::vector<SceneObject*> sceneObjects){}
void State::setLayerSprites(std::vector<sf::Sprite> LayerSprites){}
void State::addObject(SceneObject* obj){}