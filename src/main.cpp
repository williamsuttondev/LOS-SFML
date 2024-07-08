
#include "RenderLoop.h"
#include "TileSheetManager.h"
#include <iostream>
#include "TMJParser.h"
#include "ClickableButton.h"
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"

#define CHARACTER_FPS 12

void playerControlFunction(SceneObject& obj) {
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

void cleanup(std::vector<SceneObject*>& objects) {
    for(SceneObject* obj : objects) {
        if(obj->getType() == SceneObject::Type::Static) {
            delete obj->getSprite();
        } else {
            delete obj->getAnimatedSprite();
        }
    }
}

int main() {
    
    
    // gameState example

    // sf::Texture texture;
    // if (!texture.loadFromFile("res/sprite_config/sprite.png")) {
    //     std::cerr << "Error loading texture" << std::endl;
    // }

    // AnimatedSprite* animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
    // animatedSprite->setScale(0.5, 0.5);
    // SceneObject* sceneObject = new SceneObject(animatedSprite, true, playerControlFunction);

    // TMJParser tmjparser("res/Texture-Map/tile-map.tmj");
    // RenderLoop renderLoop(CHARACTER_FPS);

    

    // GameState state = GameState(&renderLoop);
    // state.loadLayerSprites(tmjparser);
    // state.addObject(sceneObject);

    // renderLoop.setState(&state);
    // renderLoop.run();

    // cleanup(renderLoop.getSceneObjects()); // implement for state 

    // gameState example


    // MenuState example

    RenderLoop renderLoop(CHARACTER_FPS);
    
    MenuState state = MenuState("res/Temp/Menu.jpg");

    renderLoop.setState(&state);

    renderLoop.run();

    // MenuState example

    return 0;
}