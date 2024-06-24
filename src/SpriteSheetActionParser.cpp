#include "SpriteSheetActionParser.h"
#include <json.hpp>
using json = nlohmann::json;

SpriteSheetActionParser& SpriteSheetActionParser::getInstance() {
    static SpriteSheetActionParser instance;
    return instance;
}

std::vector<AnimatedSpriteConfig> SpriteSheetActionParser::parseConfig(std::string_view filename) {
    std::ifstream file(filename.data());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the sprite file. Please check the directory arg: " + std::string(filename));
    }

    json j0;
    file >> j0;
    const auto& actions = j0["actions"];
    const sf::Vector2i rectSize = { j0["rectSize"]["width"], j0["rectSize"]["height"] };

    std::vector<AnimatedSpriteConfig> configs;
    configs.reserve(actions.size());

    for (const auto& action : actions) {
        configs.emplace_back(
            sf::Vector2i{ action["startPosition"]["x"], action["startPosition"]["y"] },
            rectSize,
            action["name"].get<std::string>(),
            action["frameCount"]
        );
    }

    return configs;
}
