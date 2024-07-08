#pragma once

#include "State.h"
#include "ClickableButton.h"
#include "RenderLoop.h"
#include "GameState.h"

class MenuState : public State{

private:

static void playerControlFunction(SceneObject& obj) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x + 5, obj.getAnimatedSprite()->getPosition().y);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-right") {
            obj.getAnimatedSprite()->setAction("walk-right");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x - 5, obj.getAnimatedSprite()->getPosition().y);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-left") {
            obj.getAnimatedSprite()->setAction("walk-left");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x, obj.getAnimatedSprite()->getPosition().y - 5);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-away") {
            obj.getAnimatedSprite()->setAction("walk-away");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x, obj.getAnimatedSprite()->getPosition().y + 5);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-towards") {
            obj.getAnimatedSprite()->setAction("walk-towards");
        }
    }
}

    static void changeToGameState(RenderLoop* renderLoop){

        sf::Texture texture;
        if (!texture.loadFromFile("res/sprite_config/sprite.png")) {
            std::cerr << "Error loading texture" << std::endl;
        }
        system("ls");
        AnimatedSprite* animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
        animatedSprite->setScale(0.5, 0.5);
        SceneObject* sceneObject = new SceneObject(animatedSprite, true, playerControlFunction);

        TMJParser tmjparser("res/Texture-Map/tile-map.tmj");
     
        std::shared_ptr<GameState> state = std::make_shared<GameState>(renderLoop);
        state->loadLayerSprites(tmjparser);
        state->addObject(sceneObject);

        renderLoop->setState(state);
        

    }

    static void changeToSettingsState(RenderLoop* renderLoop){
        std::cout << "Nope, no its not" << std::endl;
    }

    static void exitProgram(sf::RenderWindow* window){
        window->close();
    }

    ClickableButton m_startGame = ClickableButton(560,300,"res/Temp/StartGame.jpg", Rectangle(560,300,260,80), &changeToGameState);
    ClickableButton m_settings  = ClickableButton(560,400,"res/Temp/Settings.jpg", Rectangle(560,400,260,80), &changeToSettingsState);
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

    void handleEvents( sf::RenderWindow* window, sf::Event* event, RenderLoop* renderLoop);

    void render(sf::RenderWindow* window);

};