#pragma once


struct Rectangle{
    float xPos, yPos,width,height; // not a class, is member styling needed?
};

struct Circle{
    float xPos, yPos,radius;
};

class Colliders{

public:

    bool isRectCollision(Rectangle r1, Rectangle r2);

    bool isCircleCollision(Circle c1, Circle c2);

};