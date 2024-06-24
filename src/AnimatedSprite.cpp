// AnimatedSprite.cpp
#include "AnimatedSprite.h"
#include "SpriteSheetActionParser.h"

AnimatedSprite::AnimatedSprite(std::string_view filename, const sf::Texture& texture)
    : sf::Sprite(texture), m_currentFrame(0), m_currentConfig(nullptr) {
    m_spriteConfigs = SpriteSheetActionParser::getInstance().parseConfig(filename);
    if (!m_spriteConfigs.empty()) {
        setAction(m_spriteConfigs[1].getActionName());  // Setting initial action - assuming index 2 is valid
    }
}

AnimatedSpriteConfig* AnimatedSprite::getConfig() const {
    return m_currentConfig;
}

void AnimatedSprite::setAction(std::string_view actionName) {
    if (auto it = std::find_if(m_spriteConfigs.begin(), m_spriteConfigs.end(), 
                               [&](const AnimatedSpriteConfig& config) {
                               return config.getActionName() == actionName;
                           });
        it != m_spriteConfigs.end()) {
        m_currentConfig = &(*it);  // Set current configuration
        setTextureRect(sf::IntRect(m_currentConfig->getStartCoords(), m_currentConfig->getRectSize()));
        m_currentFrame = 0;  // Reset frame counter
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