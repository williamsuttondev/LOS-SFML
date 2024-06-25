#include "RenderLoop.h"
#include "TileSheetManager.h"
#include <iostream>
#include "Clickable.h"


#define CHARACTER_FPS 12

void playerControlFunction(SceneObject& obj) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x + 20, obj.getAnimatedSprite()->getPosition().y);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-right") {
            obj.getAnimatedSprite()->setAction("walk-right");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x - 20, obj.getAnimatedSprite()->getPosition().y);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-left") {
            obj.getAnimatedSprite()->setAction("walk-left");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x, obj.getAnimatedSprite()->getPosition().y - 20);
        if(obj.getAnimatedSprite()->getConfig()->getActionName() != "walk-away") {
            obj.getAnimatedSprite()->setAction("walk-away");
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        obj.getAnimatedSprite()->setPosition(obj.getAnimatedSprite()->getPosition().x, obj.getAnimatedSprite()->getPosition().y + 20);
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


void printSomething(){

    std::cout << "Function pointer function!" << std::endl;

}

int main() {
    // sf::Texture texture;
    // if (!texture.loadFromFile("res/sprite_config/sprite.png")) {
    //     std::cerr << "Error loading texture" << std::endl;
    // }
    // AnimatedSprite* animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
    // SceneObject* sceneObject = new SceneObject(animatedSprite, true, playerControlFunction);
    // RenderLoop renderLoop(CHARACTER_FPS);
    // renderLoop.addObject(sceneObject);
    // renderLoop.run();
    // cleanup(renderLoop.getSceneObjects());
    // return 0;
}