#pragma once

#include "State.h"
#include "ClickableButton.h"


class MenuState : public State{

private:

    ClickableButton foo = ClickableButton(10,10,"Temp/button.png");


public:

    MenuState(){



    }

    void handleEvents( sf::RenderWindow* window, sf::Event* event);

    void render(sf::RenderWindow* window);

};