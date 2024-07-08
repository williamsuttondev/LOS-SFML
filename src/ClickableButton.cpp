#include "ClickableButton.h"


void ClickableButton::setClickFunction(void (*funcPtr)()){
        m_clickFunc = funcPtr;
}

void ClickableButton::setHoverFunction(void (*funcPtr)()){
        m_hoverFunc = funcPtr;
}



Rectangle& ClickableButton::getBoxCollider(){return m_boxCollider;}