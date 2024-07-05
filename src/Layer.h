#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Layer {
public:
    Layer(int zDepth);
    void addSprite(const sf::Sprite& sprite);
    const std::vector<sf::Sprite>& getSprites() const;
    int getZDepth() const;

private:
    std::vector<sf::Sprite> m_sprites;
    int m_zDepth;
};
