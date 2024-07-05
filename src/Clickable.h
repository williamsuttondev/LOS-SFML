#pragma once

#include <iostream>

class Clickable{


private:

public:

    virtual void onClick() = 0; // Enforce implementation 

    virtual void onClick(void (*funcPtr)()) = 0; // Enforce implementation for linking function to click event

    virtual void onHover() = 0;

    virtual void onHover(void (*funcPtr)()) = 0;

};