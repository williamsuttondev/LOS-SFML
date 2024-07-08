#pragma once

#include <SFML/Graphics.hpp>
#include "SceneObject.h"

class RenderLoop; // Forward declaration to avoid circular dependancy 

class State {

protected:

    RenderLoop* m_renderLoop; // Renderloop reference to change state
    std::vector<SceneObject*> m_sceneObjects;
    std::vector<sf::Sprite> m_layerSprites;
    

public:

    State(){}
    State(RenderLoop* m_renderLoop){}

    virtual void handleEvents();
    virtual void handleEvents( sf::RenderWindow* window, sf::Event* event);
    virtual void handleEvents( sf::RenderWindow* window, sf::Event* event, RenderLoop* renderLoop);
    virtual void update();

    virtual void update(void (*func)()); // general logic usage of function pointer

    // Possible usages for timings and/or player placements
    virtual void update(void (*func)(float));
    virtual void update(void (*func)(float,float));

    virtual void render();
    virtual void render(sf::RenderWindow* window);

    virtual void changeState();
    virtual void changeState(State* state);
    virtual void cleanUp(); // Here in case states alloc to the heap


    virtual std::vector<SceneObject*> getSceneObjects();
    virtual std::vector<sf::Sprite> getLayerSprites();

    virtual void setSceneObjects(std::vector<SceneObject*> sceneObjects);
    virtual void setLayerSprites(std::vector<sf::Sprite> LayerSprites);


    virtual void addObject(SceneObject* obj);

};