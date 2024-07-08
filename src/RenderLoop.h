#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "TMJParser.h"
#include "SceneObject.h"
#include "State.h"
#include <memory>

class RenderLoop {
public:

    RenderLoop(unsigned int fps);

    void addObject(SceneObject* obj);
    void run();

    void setState(std::shared_ptr<State> state);
    std::shared_ptr<State> getState();

    sf::RenderWindow& getWindow();

private:

    std::shared_ptr<State> m_currentState;
    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Time m_frameTime;
    sf::Time m_engineTime;

};
