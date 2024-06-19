#pragma once

#include <SFML/Graphics.hpp>

class AnimatedSpriteConfig {
    public:
        AnimatedSpriteConfig(const sf::Vector2i startCoordinate, const sf::Vector2i rectSize, const std::string actionName, const int wrapNumber);
        const sf::Vector2i getStartCoords();
        const sf::Vector2i getRectSize();
        const std::string getActionName();
        const int getWrapNumber();
    private:
        const sf::Vector2i m_startCoord;
        const sf::Vector2i m_rectSize;
        const std::string m_actionName;
        const int m_wrapNumber;
};