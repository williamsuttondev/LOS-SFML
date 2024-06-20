#include <iostream>
#include "AnimatedSprite.h"
#include "SpriteSheetActionParser.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Empty black box.");
    sf::Event event;
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}