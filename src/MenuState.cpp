#include "MenuState.h"

#include "Colliders.h"


void MenuState::handleEvents(sf::RenderWindow* window, sf::Event* event){}

void MenuState::handleEvents(sf::RenderWindow* window, sf::Event* event, RenderLoop* renderLoop){

   Rectangle mouseCollider = Rectangle(
    sf::Mouse::getPosition(*window).x,
    sf::Mouse::getPosition(*window).y,
    20,20
    );

    for(ClickableButton button: m_menuButtons){
        
        if(Colliders::isRectCollision(mouseCollider,button.getBoxCollider()) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                switch (button.getGUID()) // could use an enum here that could be better for extending function ptr variants
                {

                case 0:
                    button.onClick();
                    break;
                case 1:
                    button.onClick(window);
                    break;
                case 2:
                    button.onClick(renderLoop);
                break;
                
                default:
                    break;
                }
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


