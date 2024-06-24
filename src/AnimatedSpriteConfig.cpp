#include "AnimatedSpriteConfig.h"

AnimatedSpriteConfig::AnimatedSpriteConfig(const sf::Vector2i startCoordinate, const sf::Vector2i rectSize, const std::string actionName, const int wrapNumber) : 
    m_startCoord(startCoordinate), m_rectSize(rectSize), m_actionName(actionName), m_wrapNumber(wrapNumber) {}


sf::Vector2i AnimatedSpriteConfig::getStartCoords() const {
    return this->m_startCoord;
}

sf::Vector2i AnimatedSpriteConfig::getRectSize() const {
    return this->m_rectSize;
}

std::string AnimatedSpriteConfig::getActionName() const {
    return this->m_actionName;
}

int AnimatedSpriteConfig::getWrapNumber() const {
    return this->m_wrapNumber;
}