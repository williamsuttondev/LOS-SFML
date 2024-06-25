#include "UIComponent.h"


void UIComponent::setTexture(std::string_view textureFileName){
    if (!m_UITexture.loadFromFile(textureFileName.data())){m_failedLoad = true; } // Ensure error checking 
}

void UIComponent::setSprite(){
    m_UISprite.setTexture(m_UITexture);
    m_UISprite.setPosition(m_xPos,m_yPos);
}


sf::Texture& UIComponent::getTexture(){return m_UITexture;}

const sf::Sprite&  UIComponent::getSprite(){return m_UISprite;}

std::pair<float,float> UIComponent::getPosition(){

    return std::make_pair(m_xPos,m_yPos);

}

void UIComponent::setPosition(float x, float y){
    m_xPos = x;
    m_yPos = y;
    m_UISprite.setPosition(m_xPos,m_yPos);    
}