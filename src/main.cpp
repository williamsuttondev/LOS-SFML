#include "RenderLoop.h"
#include "TileSheetManager.h"
#include <iostream>

#define FPS 12

void playerControlFunction(SceneObject& obj) {
    // Do nothing for now.
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
    sf::Texture texture;
    if (!texture.loadFromFile("res/sprite_config/sprite.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    AnimatedSprite* animatedSprite = new AnimatedSprite("res/sprite_config/sprite_config.json", texture);
    SceneObject* sceneObject = new SceneObject(animatedSprite, true, playerControlFunction);
    RenderLoop renderLoop(FPS);
    renderLoop.addObject(sceneObject);
    renderLoop.run();
    cleanup(renderLoop.getSceneObjects());
    return 0;
}