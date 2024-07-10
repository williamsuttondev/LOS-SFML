#pragma once

#include "State.h"
#include "TMJParser.h"
#include <iostream>

class GameState : public State{

private:

    static void playerControlFunction(SceneObject& obj);

    sf::Texture m_texture;
    AnimatedSprite* m_animatedSprite;
    TMJParser tmjparser = TMJParser("res/Texture-Map/tile-map.tmj"); // really didnt wanna do this 

public:

    GameState(){}

    GameState(RenderLoop* m_renderLoop){
         if (!m_texture.loadFromFile("res/sprite_config/sprite.png")) {
            std::cerr << "Error loading texture" << std::endl;
        }

        m_animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", m_texture);
        m_animatedSprite->setScale(0.5, 0.5);
        SceneObject* sceneObject = new SceneObject(m_animatedSprite, true, playerControlFunction);
        
        

        // loadLayerSprites(tmjparser);

        m_layerSprites = tmjparser.getLayerSprites();
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