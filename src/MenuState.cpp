#include "MenuState.h"



void MenuState::handleEvents(sf::RenderWindow* window, sf::Event* event){

    

}

void MenuState::render(sf::RenderWindow* window){

    window->clear(sf::Color::Transparent);

    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;  // Use sf::BlendAlpha to handle transparency correctly

    window->draw(foo.getSprite());


    window->display();

}


