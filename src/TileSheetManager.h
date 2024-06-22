#include <SFML/Graphics.hpp>
#include <vector>

class TileSheetManager{

private:

public:

    static std::vector<sf::Texture> generateTileMapFromImage(sf::Image& tileSheet, int tileWidth, int tileHeight);

};