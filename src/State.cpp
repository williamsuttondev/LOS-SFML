#include "State.h"
#include <iostream>

void State::handleEvents(){
    std::cout << "handleEvents function is to be implemented in a child class" << std::endl;
} 

void State::handleEvents( sf::RenderWindow* window, sf::Event* event){
    std::cout << "handleEvents function is to be implemented in a child class" << std::endl;
}

void State::update(){
    std::cout << "Update function is to be implemented in a child class" << std::endl;
} 

void State::update(void (*func)()){
    std::cout << "Update function is to be implemented in a child class" << std::endl;
} 
void State::update(void (*func)(float)){
    std::cout << "Update function is to be implemented in a child class" << std::endl;
} 
void State::update(void (*func)(float,float)){
    std::cout << "Update function is to be implemented in a child class" << std::endl;
} 


void State::render(){
    std::cout << "render function is to be implemented in a child class" << std::endl;
}

void State::render(sf::RenderWindow* window){
    std::cout << "render function is to be implemented in a child class" << std::endl;
}


void State::changeState(){
    std::cout << "changeState function is to be implemented in a child class" << std::endl;
}
void State::changeState(State* state){
    std::cout << "changeState function is to be implemented in a child class" << std::endl;
}
void State::cleanUp(){
    std::cout << "cleanUp function is to be implemented in a child class" << std::endl;
}

std::vector<SceneObject*> State::getSceneObjects(){
    std::cout << "getSceneObjects function is to be implemented in a child class" << std::endl;
    return m_sceneObjects;
}

std::vector<sf::Sprite> State::getLayerSprites(){
    std::cout << "getLayerSprites function is to be implemented in a child class" << std::endl;
    return m_layerSprites;
}

void State::setSceneObjects(std::vector<SceneObject*> sceneObjects){
    std::cout << "setSceneObjects function is to be implemented in a child class" << std::endl;
}
void State::setLayerSprites(std::vector<sf::Sprite> LayerSprites){
    std::cout << "setLayerSprites function is to be implemented in a child class" << std::endl;
}

void State::addObject(SceneObject* obj) {
    m_sceneObjects.push_back(obj);
}