#include "RenderLoop.h"
#include "TileSheetManager.h"
#include <iostream>
#include "ClickableButton.h"
#include <SFML/Graphics.hpp>
 

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

    ClickableButton c = ClickableButton(40,10,"res/sprite_config/sprite.png");


    Rectangle r = {40,10,100,100};

    sf::RectangleShape rs(sf::Vector2(r.width,r.height));
    sf::RectangleShape rs2(sf::Vector2(r.width,r.height));

    rs.setPosition(r.xPos,r.yPos);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        sf::Vector2i position = sf::Mouse::getPosition(window);
        // std::cout << position.x << "," << position.y << std::endl;

        rs2.setPosition( position.x - r.width/2,position.y-r.height/2);

        // Draw the sprite
        window.draw(c.getSprite());
        window.draw(rs);
        window.draw(rs2);

        if(Colliders::isRectCollision(r,Rectangle(position.x - r.width/2,position.y-r.height/2,r.width,r.height)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            std::cout << "Clicked button" << std::endl;
        }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){std::cout << "Not clicked it" << std::endl;}

        // Update the window
        window.display();
    }

}