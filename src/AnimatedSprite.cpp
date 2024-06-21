// AnimatedSprite.cpp
#include "AnimatedSprite.h"
#include "SpriteSheetActionParser.h"
AnimatedSprite::AnimatedSprite(std::string_view filename, const sf::Texture& texture)
    : sf::Sprite(texture), m_currentFrame(0), m_currentConfig(nullptr) {
    m_spriteConfigs = SpriteSheetActionParser::getInstance().parseConfig(filename);
    if (!m_spriteConfigs.empty()) {
        setAction(m_spriteConfigs[2].getActionName());  // Setting initial action - assuming index 2 is valid
    }
}

void AnimatedSprite::setAction(std::string_view actionName) {
    auto it = std::find_if(m_spriteConfigs.begin(), m_spriteConfigs.end(), 
                           [actionName](const AnimatedSpriteConfig& config) {
                               return config.getActionName() == actionName;
                           });

    if (it != m_spriteConfigs.end()) {
        m_currentConfig = &(*it);  // Store the pointer to the current config
        const sf::Vector2i startCoord = m_currentConfig->getStartCoords();
        const sf::Vector2i rectSize = m_currentConfig->getRectSize();
        setTextureRect(sf::IntRect(startCoord.x, startCoord.y, rectSize.x, rectSize.y));
        m_currentFrame = 0;  // Reset frame when action changes
    }
}

void AnimatedSprite::incrementFrame() {
    if (m_spriteConfigs.empty() || m_currentConfig == nullptr) return;

    ++m_currentFrame;
    if (m_currentFrame >= m_currentConfig->getWrapNumber()) {
        m_currentFrame = 0; // wraps around
    }

    // Calculate new texture rectangle for the sprite
    const sf::Vector2i startCoord = m_currentConfig->getStartCoords();
    const sf::Vector2i rectSize = m_currentConfig->getRectSize();
    const int newLeft = startCoord.x + (rectSize.x * m_currentFrame);

    setTextureRect(sf::IntRect(newLeft, startCoord.y, rectSize.x, rectSize.y));
}