#pragma once

#include "Clickable.h"
#include "Colliders.h"
#include "UIComponent.h"
#include <SFML/Graphics.hpp>

// https://www.youtube.com/watch?v=Qn977W9HjWM

class ClickableButton : public Clickable, public UIComponent{


private:


    Rectangle m_boxCollider;


public:


// So... many... constructors....

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

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*clickFunc)(sf::RenderWindow* window)){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
        setClickFunction(clickFunc);
    }

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*clickFunc)(), void (*hoverFunc)(sf::RenderWindow* window)){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
        setClickFunction(clickFunc);
        setHoverFunction(hoverFunc);
    }

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*clickFunc)(sf::RenderWindow* window), void (*hoverFunc)(sf::RenderWindow* window)){
        m_xPos = x;
        m_yPos = y;
        setTexture(textureFileName);  
        setSprite();    
        setBoxCollider(boxCollider);
        setClickFunction(clickFunc);
        setHoverFunction(hoverFunc);
    }

    ClickableButton(float x, float y, std::string_view textureFileName, Rectangle boxCollider, void (*clickFunc)(RenderLoop* renderLoop), void (*hoverFunc)(RenderLoop* renderLoop)){
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



    /////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //          Extend these functions if needed to allow for parameters in your function pointers! 
    //          Example void (*funcPtr)(int x, int y), void (*funcPtr)(float a, std::string abc)
    //
    //          Note the pairs of functions onClick setClickFunction and onHover setHoverFunction for easy readability. 
    //          You WILL have to go to Clickable.h and add your variables to hold your corresponding function pointer to extend this functionality
    //          You WILL also have to go to the constructor definitions and add ones that allow for your specfic function pointer types. Luckily examples are in this file above, but it is cumbersome
    //
    //       Base pair of onclick with corresponding empty void function
    /**/     void onClick();
    /**/     void setClickFunction(void (*funcPtr)());
    //       Base pair of onclick with corresponding empty void function

    //       Base pair of onHover with corresponding empty void function
    /**/     void onHover();
    /**/     void setHoverFunction(void (*funcPtr)());
    //       Base pair of onHover with corresponding empty void function
    //
    /**/     void onClick(sf::RenderWindow* window);
    /**/     void setClickFunction(void (*funcPtr)(sf::RenderWindow* window));
    //
    /**/     void onHover(sf::RenderWindow* window);
    /**/     void setHoverFunction(void (*funcPtr)(sf::RenderWindow* window));
    //
    /**/     void onClick(RenderLoop* renderLoop);
    /**/     void setClickFunction(void (*funcPtr)(RenderLoop* renderLoop));
    //
    /**/     void onHover(RenderLoop* renderLoop);
    /**/     void setHoverFunction(void (*funcPtr)(RenderLoop* renderLoop));
    /////////////////////////////////////////////////////////////////////////////////////////////////

    // Overloaded functions

};

