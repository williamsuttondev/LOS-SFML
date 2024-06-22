#include "RenderLoop.h"
#include "TileSheetManager.h"

#define FPS 12

int main() {


    sf::Image f;
    f.loadFromFile("../res/sprite_config/sprite.png");

    std::vector<sf::Texture> tex = TileSheetManager::generateTileMapFromImage(f,10,10);

    sf::Sprite sprite = sf::Sprite(tex[1]);

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
 
        // Draw the sprite
        window.draw(sprite);
 

 
        // Update the window
        window.display();
    }
    

    // RenderLoop renderLoop(FPS);
    // renderLoop.run();
    return 0;
}