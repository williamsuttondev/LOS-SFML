#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

class Clickable{


private:

    int m_xPos, m_yPos;



public:

    Clickable(){}

    virtual void onClick() = 0; // Enforce implementation 

    virtual void onClick() = 0; // Enforce implementation

};



class TestClickable : public Clickable{


public:

    void onClick(){

        std::cout << "Clicked!" << std::endl;

    }

};