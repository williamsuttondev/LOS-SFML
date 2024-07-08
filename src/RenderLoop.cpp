#include "RenderLoop.h"
#include <iostream>

#define ENGINE_FPS 60

RenderLoop::RenderLoop(unsigned int fps)
    : m_window(sf::VideoMode(1280, 928), "LOS-SFML"),
      m_frameTime(sf::seconds(1.0f / fps))
      {
    m_engineTime = sf::seconds(1.0f / ENGINE_FPS);
}

void RenderLoop::run() {

    sf::Clock updateClock; // Clock for tracking the update interval
    sf::Clock eventClock;

    while (m_window.isOpen()) {
        if(eventClock.getElapsedTime() >= m_engineTime) {
            m_currentState->handleEvents(&m_window, &m_event);
            eventClock.restart();
        }
        if (updateClock.getElapsedTime() >= m_frameTime) {
            m_currentState->update();
            updateClock.restart(); // Restart the update clock
        }
        m_currentState->render(&m_window);
    }

}

void RenderLoop::setState(State* state){m_currentState = state;}
State* RenderLoop::getState(){return m_currentState;}

sf::RenderWindow& RenderLoop::getWindow(){return m_window;}