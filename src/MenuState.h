#pragma once

#include "State.h"
#include "ClickableButton.h"


class MenuState : public State{

private:

    
    ClickableButton m_startGame = ClickableButton(560,300,"res/Temp/StartGame.jpg");
    ClickableButton m_settings  = ClickableButton(560,400,"res/Temp/Settings.jpg");
    ClickableButton m_exit       = ClickableButton(560,500,"res/Temp/Exit.jpg");

    sf::Texture m_backgroundImageData;
    sf::Sprite  m_backgroundImage;


public:

    MenuState(){
    }

    MenuState(std::string_view filename){
        if (!m_backgroundImageData.loadFromFile(filename.data())){std::cout << "Error loading: " << filename.data() << std::endl;}
        m_backgroundImage.setTexture(m_backgroundImageData);
    }

    void handleEvents( sf::RenderWindow* window, sf::Event* event);

    void render(sf::RenderWindow* window);

};