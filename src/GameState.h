#pragma once

#include "State.h"
#include "TMJParser.h"

class GameState : public State{

private:


public:

    GameState(){}

    GameState(RenderLoop* m_renderLoop){}

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