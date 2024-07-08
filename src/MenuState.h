#pragma once

#include "State.h"
#include "ClickableButton.h"
#include "RenderLoop.h"

class MenuState : public State{

private:

    static void changeToGameState(RenderLoop* renderLoop){
        
    }

    static void changeToSettingsState(RenderLoop* renderLoop){
        
    }

    static void exitProgram(sf::RenderWindow* window){
        window->close();
    }

    ClickableButton m_startGame = ClickableButton(560,300,"res/Temp/StartGame.jpg", Rectangle(560,300,260,80), &changeToGameState);
    ClickableButton m_settings  = ClickableButton(560,400,"res/Temp/Settings.jpg", Rectangle(560,400,260,80), &changeToGameState);
    ClickableButton m_exit      = ClickableButton(560,500,"res/Temp/Exit.jpg", Rectangle(560,500,260,80), &exitProgram);

    std::vector<ClickableButton> m_menuButtons = {
        m_startGame,
        m_settings,
        m_exit
    };

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