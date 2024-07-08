#include "State.h"
#include <iostream>

void State::handleEvents(){
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
    std::cout << "Render function is to be implemented in a child class" << std::endl;
} 
void State::render(std::vector<sf::Sprite> sprites){
    std::cout << "Render function is to be implemented in a child class" << std::endl;
} 
void State::render(std::vector<SceneObject> sprites){
    std::cout << "Render function is to be implemented in a child class" << std::endl;
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

