#include "ClickableButton.h"


void ClickableButton::onClick(){m_clickFunc();}

void ClickableButton::onHover(){m_clickFunc();}


void ClickableButton::setClickFunction(void (*funcPtr)()){
        m_clickFunc = funcPtr;
}

void ClickableButton::setHoverFunction(void (*funcPtr)()){
        m_hoverFunc = funcPtr;
}

void ClickableButton::setClickFunction(void (*funcPtr)(sf::RenderWindow* window)){
        m_clickFuncWin = funcPtr;
}

void ClickableButton::setHoverFunction(void (*funcPtr)(sf::RenderWindow* window)){
        m_hoverFuncWin = funcPtr;
}

void ClickableButton::setClickFunction(void (*funcPtr)(RenderLoop* renderLoop)){
        m_clickFuncLoop = funcPtr;
}

void ClickableButton::setHoverFunction(void (*funcPtr)(RenderLoop* renderLoop)){
        m_hoverFuncLoop = funcPtr;
}


Rectangle& ClickableButton::getBoxCollider(){return m_boxCollider;}

void ClickableButton::setBoxCollider(Rectangle r){m_boxCollider = r;}