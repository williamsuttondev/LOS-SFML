#pragma once


struct Rectangle{
    float xPos, yPos,width,height; // not a class, is member styling needed?
};

struct Circle{
    float xPos, yPos,radius;
};

class Colliders{

public:

    static bool isRectCollision(Rectangle r1, Rectangle r2);

    static bool isCircleCollision(Circle c1, Circle c2);

};