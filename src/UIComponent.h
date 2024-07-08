#pragma once

#include <SFML/Graphics.hpp>

class UIComponent{

protected:
    
    float m_xPos;
    float m_yPos;

    sf::Texture m_UITexture;
    sf::Sprite  m_UISprite;

    bool m_failedLoad = false;

public:

    // Setters
    void setTexture(std::string_view textureFileName);

    void setSprite();

    void setPosition(float x, float y);
    // Setters

    // Getters
    const sf::Sprite& getSprite();

    sf::Texture& getTexture();

    std::pair<float,float> getPosition();
    // Getters


};