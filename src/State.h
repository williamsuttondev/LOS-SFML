#pragma once

#include <SFML/Graphics.hpp>
#include "SceneObject.h"

class RenderLoop; // Forward declaration to avoid circular dependancy 

class State {

private:

    RenderLoop* m_renderLoop; // Renderloop reference to change state

public:

    std::string f = "Hello world!";

    State(){}
    State(RenderLoop* m_renderLoop){}

    void handleEvents();
    void update();

    void update(void (*func)()); // general logic usage of function pointer

    // Possible usages for timings and/or player placements
    void update(void (*func)(float));
    void update(void (*func)(float,float));

    void render();
    void render(std::vector<sf::Sprite> sprites);
    void render(std::vector<SceneObject> sprites);


    void changeState();
    void changeState(State* state);
    void cleanUp(); // Here in case states alloc to the heap

};