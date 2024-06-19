#pragma once

#include "SFML/Graphics.hpp"
#include "AnimatedSpriteConfig.h"
#include <vector>
#include <fstream>

class SpriteSheetActionParser {
public:
    static SpriteSheetActionParser& getInstance();
    std::vector<AnimatedSpriteConfig> parseConfig(std::string_view filename);
private:
    SpriteSheetActionParser() {}
    ~SpriteSheetActionParser() {}
    SpriteSheetActionParser(const SpriteSheetActionParser&) = delete;
    SpriteSheetActionParser& operator=(const SpriteSheetActionParser&) = delete;
};