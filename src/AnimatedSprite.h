#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSpriteConfig.h"
#include <vector>

/**
 * @class AnimatedSprite
 * @brief A sprite class that supports animation via different configurations.
 *
 * This class extends the SFML Sprite class to include animation capabilities.
 * It facilitates switching between different animation actions and frame increments.
 */
class AnimatedSprite : public sf::Sprite {
public:
    /**
     * @brief Constructs an AnimatedSprite object with a given filename and texture.
     * 
     * @param filename A string view representing the name of the sprite file.
     * @param texture A reference to an SFML Texture object used by the sprite.
     */
    AnimatedSprite(std::string_view filename, const sf::Texture& texture);

    /**
     * @brief Sets the current animation action.
     * 
     * This function allows the user to change the current action being animated
     * based on the provided action name.
     *
     * @param actionName A string view representing the name of the action to be set.
     */
    void setAction(std::string_view actionName);

    /**
     * @brief Increments the current animation frame.
     * 
     * This function moves to the next frame in the current animation configuration.
     */
    void incrementFrame();

private:
    std::vector<AnimatedSpriteConfig> m_spriteConfigs; ///< A list of sprite configurations for different actions.
    int m_currentFrame; ///< The current frame index of the animation.
    AnimatedSpriteConfig* m_currentConfig; ///< Pointer to the current animation configuration in use.
};