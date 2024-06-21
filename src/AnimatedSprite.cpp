// AnimatedSprite.cpp
#include "AnimatedSprite.h"
#include "SpriteSheetActionParser.h"
AnimatedSprite::AnimatedSprite(std::string_view filename, const sf::Texture& texture) : sf::Sprite(texture) {
    m_spriteConfigs = SpriteSheetActionParser::getInstance().parseConfig(filename);
    m_currentFrame = 0;
    if (!m_spriteConfigs.empty()) {
        setAction(m_spriteConfigs[0].getActionName());
    }
}

void AnimatedSprite::setAction(std::string_view actionName) {
    auto it = std::find_if(m_spriteConfigs.begin(), m_spriteConfigs.end(), 
                           [actionName](const AnimatedSpriteConfig& config) {
                               return config.getActionName() == actionName;
                           });

    if (it != m_spriteConfigs.end()) {
        const sf::Vector2i startCoord = it->getStartCoords();
        const sf::Vector2i rectSize = it->getRectSize();
        setTextureRect(sf::IntRect(startCoord.x, startCoord.y, rectSize.x, rectSize.y));
    }
}

void AnimatedSprite::incrementFrame() {
    if (m_spriteConfigs.empty()) return;

    const auto& currentConfig = m_spriteConfigs.front();
    
    ++m_currentFrame;
    if (m_currentFrame >= currentConfig.getWrapNumber()) {
        m_currentFrame = 0; // wraps around
    }

    // Calculate new texture rectangle for the sprite
    const sf::Vector2i startCoord = currentConfig.getStartCoords();
    const sf::Vector2i rectSize = currentConfig.getRectSize();
    const int newLeft = startCoord.x + (rectSize.x * m_currentFrame);

    setTextureRect(sf::IntRect(newLeft, startCoord.y, rectSize.x, rectSize.y));
}