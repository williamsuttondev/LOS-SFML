#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSpriteConfig.h"
#include <vector>

class AnimatedSprite : public sf::Sprite {
public:
    void setAction(std::string_view actionName);
    AnimatedSprite(std::string_view filename);
    void incrementFrame();
private:
    std::vector<AnimatedSpriteConfig> m_spriteConfigs;
    int m_currentFrame;
};