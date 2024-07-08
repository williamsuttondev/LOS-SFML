#include "MenuState.h"

#include "Colliders.h"

void MenuState::handleEvents(sf::RenderWindow* window, sf::Event* event){



   Rectangle mouseCollider = Rectangle(
    sf::Mouse::getPosition(*window).x,
    sf::Mouse::getPosition(*window).y,
    20,20
    );

    for(ClickableButton button: m_menuButtons){

        if(Colliders::isRectCollision(mouseCollider,button.getBoxCollider()) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                button.onClick();
        }
    }

    
}

void MenuState::render(sf::RenderWindow* window){

    window->clear(sf::Color::Transparent);

    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;  // Use sf::BlendAlpha to handle transparency correctly

    window->draw(m_backgroundImage);
    
    for(ClickableButton button: m_menuButtons){
        window->draw(button.getSprite());
    }

    window->display();

}


