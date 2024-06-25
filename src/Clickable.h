#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

class Clickable{


private:

public:

    Clickable(){}

    virtual void onClick() = 0; // Enforce implementation 

    virtual void onClick(void (*funcPtr)()) = 0; // Enforce implementation for linking function to click event

};