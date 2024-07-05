#include "Layer.h"

Layer::Layer(int zDepth)
    : m_zDepth(zDepth) {}

void Layer::addSprite(const sf::Sprite& sprite) {
    m_sprites.push_back(sprite);
}

const std::vector<sf::Sprite>& Layer::getSprites() const {
    return m_sprites;
}

int Layer::getZDepth() const {
    return m_zDepth;
}