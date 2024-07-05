#pragma once

#include "Clickable.h"
#include "Colliders.h"
#include "UIComponent.h"
#include <SFML/Graphics.hpp>

class ClickableButton : public Clickable, public UIComponent{


private:


    Rectangle m_boxCollider;


public:

    ClickableButton(float x, float y){

        m_xPos = x;
        m_yPos = y;
    }

    ClickableButton(float x, float y, std::string_view textureFileName){

        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    

    }


    // Setters
    

    void setBoxCollider(Rectangle r);

    // Setters

    // Getters


    Rectangle& getBoxCollider();

    // Getters

    // Overloaded functions

    void onClick();

    void onClick(void (*funcPtr)());

    void onHover();

    void onHover(void (*funcPtr)());

    // Overloaded functions

};

