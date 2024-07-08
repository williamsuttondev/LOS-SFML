#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderLoop.h"

class Clickable{


protected:

    void (*m_clickFunc)();
    void (*m_hoverFunc)();

    void (*m_clickFuncWin)(sf::RenderWindow* window);
    void (*m_hoverFuncWin)(sf::RenderWindow* window);

    void (*m_clickFuncLoop)(RenderLoop* renderLoop);
    void (*m_hoverFuncLoop)(RenderLoop* renderLoop);



public:

    virtual void onClick() = 0;
    
    virtual void onHover() = 0;

    virtual void setClickFunction(void (*funcPtr)()) = 0;

    virtual void setHoverFunction(void (*funcPtr)()) = 0;

};