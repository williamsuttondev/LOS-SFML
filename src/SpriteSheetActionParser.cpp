#include "SpriteSheetActionParser.h"
#include <json.hpp>
using json = nlohmann::json;
SpriteSheetActionParser& SpriteSheetActionParser::getInstance() {
    static SpriteSheetActionParser instance;
    return instance;
}

std::vector<AnimatedSpriteConfig> parseConfig(std::string_view filename) {
    std::ifstream file(filename.data());
    if(!file.is_open()) {
        throw std::runtime_error("Could not open the sprite file\nPlease check the directory arg\n" + std::string(filename));
    }
    json j0;
    file >> j0;
    file.close();
    std::vector<AnimatedSpriteConfig> configs;
    auto actions = j0["actions"];
    for(const auto& action : actions) {
        const std::string name = action["name"];
        const int frameCount = action["frameCount"];
        const sf::Vector2i startPosition = {action["startPosition"]["x"], action["startPosition"]["y"]};
        const sf::Vector2i rectSize = {j0["rectSize"]["width"], j0["rectSize"]["height"]};
        configs.push_back(AnimatedSpriteConfig(startPosition, rectSize, name, frameCount));
    }
    return configs;
}