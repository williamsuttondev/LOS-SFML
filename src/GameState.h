#pragma once

#include "State.h"
#include "TMJParser.h"
#include <iostream>

class GameState : public State{

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

    sf::Texture m_texture;
    AnimatedSprite* m_animatedSprite;


        // if (!texture.loadFromFile("res/sprite_config/sprite.png")) {
        //     std::cerr << "Error loading texture" << std::endl;
        // }

        // AnimatedSprite* animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
        // animatedSprite->setScale(0.5, 0.5);
        // SceneObject* sceneObject = new SceneObject(animatedSprite, true, playerControlFunction);

        // TMJParser tmjparser("res/Texture-Map/tile-map.tmj");
public:

    GameState(){}

    GameState(RenderLoop* m_renderLoop){
         if (!m_texture.loadFromFile("res/sprite_config/sprite.png")) {
            std::cerr << "Error loading texture" << std::endl;
        }

        m_animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", m_texture);
        m_animatedSprite->setScale(0.5, 0.5);
        SceneObject* sceneObject = new SceneObject(m_animatedSprite, true, playerControlFunction);
        
        TMJParser tmjparser("res/Texture-Map/tile-map.tmj");

        loadLayerSprites(tmjparser);
        addObject(sceneObject);
        

    }

    void handleEvents();
    void handleEvents(sf::RenderWindow* window, sf::Event* event);
    void update();

    void render();
    void render(sf::RenderWindow* window);


    void changeState();
    void changeState(State* state);
    void cleanUp(); // Here in case states alloc to the heap


    std::vector<SceneObject*> getSceneObjects();
    std::vector<sf::Sprite> getLayerSprites();

    void setSceneObjects(std::vector<SceneObject*> sceneObjects);
    void setLayerSprites(std::vector<sf::Sprite> LayerSprites);
    void loadLayerSprites(TMJParser tmjParser);
    void addObject(SceneObject* obj);

};