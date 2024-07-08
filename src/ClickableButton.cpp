#include "ClickableButton.h"


void ClickableButton::onClick(){m_clickFunc();}
void ClickableButton::setClickFunction(void (*funcPtr)()){
        std::cout << "Hello.... " << std::endl;
        m_clickFunc = funcPtr;
}

void ClickableButton::onHover(){m_clickFunc();}
void ClickableButton::setHoverFunction(void (*funcPtr)()){
        std::cout << "Hello.... " << std::endl;
        m_hoverFunc = funcPtr;
}


void ClickableButton::onClick(sf::RenderWindow* window){m_clickFuncWin(window);}
void ClickableButton::setClickFunction(void (*funcPtr)(sf::RenderWindow* window)){m_clickFuncWin = funcPtr;}

void ClickableButton::onHover(sf::RenderWindow* window){m_clickFuncWin(window);}
void ClickableButton::setHoverFunction(void (*funcPtr)(sf::RenderWindow* window)){m_clickFuncWin = funcPtr;}



void ClickableButton::onClick(RenderLoop* renderLoop){m_clickFuncLoop(renderLoop);}
void ClickableButton::setClickFunction(void (*funcPtr)(RenderLoop* renderLoop)){m_clickFuncLoop = funcPtr;}

void ClickableButton::onHover(RenderLoop* renderLoop){m_clickFuncLoop(renderLoop);}
void ClickableButton::setHoverFunction(void (*funcPtr)(RenderLoop* renderLoop)){m_clickFuncLoop = funcPtr;}


Rectangle& ClickableButton::getBoxCollider(){return m_boxCollider;}

void ClickableButton::setBoxCollider(Rectangle r){m_boxCollider = r;}


int ClickableButton::getGUID(){return m_GUID;}
void ClickableButton::setGUID(int GUID){m_GUID = GUID;}