#include "Colliders.h"
#include <math.h>


bool Colliders::isRectCollision(Rectangle r1, Rectangle r2){
    return (
        r1.xPos < r2.xPos + r2.width &&
        r1.xPos + r1.width > r2.xPos &&
        r1.yPos < r2.yPos + r2.height &&
        r1.yPos + r1.height > r2.yPos
    );
}

bool Colliders::isCircleCollision(Circle c1, Circle c2){

  float dx = c1.xPos - c2.xPos;
  float dy = c1.yPos - c2.yPos;
  float distance = sqrt(dx * dx + dy * dy);

  return distance < c1.radius + c2.radius;
}