#pragma once

#include <iostream>

class Clickable{


protected:

    void (*m_clickFunc)();
    void (*m_hoverFunc)();


public:

    
    virtual void setClickFunction(void (*funcPtr)()) = 0;

    virtual void setHoverFunction(void (*funcPtr)()) = 0;
    
};