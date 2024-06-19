#include "AnimatedSpriteConfig.h"

AnimatedSpriteConfig::AnimatedSpriteConfig(const sf::Vector2i startCoordinate, const sf::Vector2i rectSize, const std::string actionName, const int wrapNumber) : 
    m_startCoord(startCoordinate), m_rectSize(rectSize), m_actionName(actionName), m_wrapNumber(wrapNumber) {}

