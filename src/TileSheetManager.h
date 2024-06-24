#include <SFML/Graphics.hpp>
#include <vector>


/**
 * @class TileSheetManager
 * @brief A static class that manages tilesheet computations
 *
 * This class is meant as a set of functions that can be used to manipulate and generate tilemap based objects respectively.
 * 
 */

class TileSheetManager{

private:

public:
    /**
     * @brief Generates a tilemap from an incoming image and predefined width and height parameters
     * 
     * @param tileSheet  A reference to an sf::Image object, this is used to generate the tilemap with.
     * @param tileWidth  An integer to dictate the width of tiles in the map
     * @param tileHeight An integer to dictate the height of tiles in the map
     *      
     */
    static std::vector<sf::Texture> generateTileMapFromImage(sf::Image& tileSheet, int tileWidth, int tileHeight);

};