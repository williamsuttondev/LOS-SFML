#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

class Clickable{


private:

    int m_xPos, m_yPos;



public:

    Clickable(){}

    virtual void onClick() = 0; // Enforce implementation 

    virtual void onClick(void (*funcPtr)()) = 0; // Enforce implementation for linking function to click event

};