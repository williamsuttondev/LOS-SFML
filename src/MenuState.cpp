#include "MenuState.h"



void MenuState::handleEvents(sf::RenderWindow* window, sf::Event* event){

   std::cout << sf::Mouse::getPosition(*window).x << "," <<  sf::Mouse::getPosition(*window).y << std::endl;

}

void MenuState::render(sf::RenderWindow* window){

    window->clear(sf::Color::Transparent);

    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;  // Use sf::BlendAlpha to handle transparency correctly

    window->draw(m_backgroundImage);
    window->draw(m_startGame.getSprite());
    window->draw(m_settings.getSprite());
    window->draw(m_exit.getSprite());

    window->display();

}


