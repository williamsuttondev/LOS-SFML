#include <SFML/Graphics.hpp>
#include <vector>


// Tilesheet Input:
//     Accept a tilesheet image as input.
// Splitting Functionality:
//     Split the tilesheet into equal-sized parts based on the given dimensions (e.g., 45x45 pixels).
// Output Textures:
//     Return a list of sf::Textures containing each split part of the tilesheet.

// Function or Method:
//     Implement a function or method to handle the splitting process.
//     Parameters should include the tilesheet image and the size of each tile (width and height).

// Image Handling:
//     Use SFML (sf::Texture and sf::Image) to load and manipulate the tilesheet image.
//     Ensure proper handling of image boundaries to avoid errors if the image dimensions are not a perfect multiple of the tile size.

// Texture Creation:
//     Create sf::Texture objects for each split part of the tilesheet.
//     Store each texture in a list to be returned by the function.


class TileSheetManager{

private:

public:

    static std::vector<sf::Texture> generateTileMapFromImage(sf::Image& tileSheet, int tileWidth, int tileHeight);

};