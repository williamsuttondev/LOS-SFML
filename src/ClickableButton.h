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

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
    }

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*m_clickFunc)()){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
        setClickFunction(m_clickFunc);
    }


    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*clickFunc)(), void (*hoverFunc)()){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
        setClickFunction(clickFunc);
        setHoverFunction(hoverFunc);
    }

    // Setters


    void setBoxCollider(Rectangle r);

    // Setters

    // Getters


    Rectangle& getBoxCollider();

    // Getters

    // Overloaded functions

    void onClick();

    void onHover();

    void setClickFunction(void (*funcPtr)());

    void setHoverFunction(void (*funcPtr)());

    // Overloaded functions

};

