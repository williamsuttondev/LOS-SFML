#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "TMJParser.h"
#include "SceneObject.h"
#include "State.h"


class RenderLoop {
public:

    RenderLoop(unsigned int fps);

    void addObject(SceneObject* obj);
    void run();

    void setState(State* state);
    State* getState();


private:

    State* m_currentState;
    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Time m_frameTime;
    sf::Time m_engineTime;

};
