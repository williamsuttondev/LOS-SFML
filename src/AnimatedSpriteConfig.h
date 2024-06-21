#pragma once

#include <SFML/Graphics.hpp>

/**
 * @class AnimatedSpriteConfig
 * @brief A class to store configuration for an animated sprite.
 *
 * This class holds the details necessary for configuring an animated sprite, 
 * including the starting coordinate, the size of each frame, the name of the action, 
 * and the number of times the animation wraps.
 */
class AnimatedSpriteConfig {
    public:
        /**
         * @brief Constructs an AnimatedSpriteConfig object.
         * 
         * @param startCoordinate Initial coordinate of the sprite on the texture.
         * @param rectSize Size of each individual frame of the animation.
         * @param actionName Name of the action that the animation represents.
         * @param wrapNumber Number of times the animation should wrap.
         */
        AnimatedSpriteConfig(const sf::Vector2i startCoordinate, const sf::Vector2i rectSize, const std::string actionName, const int wrapNumber);

        /**
         * @brief Gets the starting coordinates of the sprite.
         * 
         * @return sf::Vector2i Starting coordinates on the texture.
         */
        sf::Vector2i getStartCoords() const;

        /**
         * @brief Gets the size of the rectangle for each frame.
         * 
         * @return sf::Vector2i Size of each frame.
         */
        sf::Vector2i getRectSize() const;

        /**
         * @brief Gets the name of the action.
         * 
         * @return std::string The name of the action.
         */
        std::string getActionName() const;

        /**
         * @brief Gets the number of times the animation wraps.
         * 
         * @return int The wrap number.
         */
        int getWrapNumber() const;

    private:
        const sf::Vector2i m_startCoord;    /**< Starting coordinates of the sprite on the texture. */
        const sf::Vector2i m_rectSize;      /**< Size of each individual frame of the animation. */
        const std::string m_actionName;     /**< Name of the action that the animation represents. */
        const int m_wrapNumber;             /**< Number of times the animation should wrap. */
};