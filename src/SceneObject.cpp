#include "SceneObject.h"

SceneObject::SceneObject(sf::Sprite* sprite, bool playerControlled, ControlFunction controlFunction) : 
m_type(Type::Static), m_sprite(sprite), m_playerControlled(playerControlled), m_controlFunction(controlFunction)
{}

SceneObject::SceneObject(AnimatedSprite* sprite, bool playerControlled, ControlFunction controlFunction) : 
m_type(Type::Animated), m_animatedSprite(sprite), m_playerControlled(playerControlled), m_controlFunction(controlFunction)
{}

SceneObject::Type SceneObject::getType() const {
    return m_type;
}

sf::Sprite* SceneObject::getSprite() const { return (m_type == Type::Static) ? m_sprite : nullptr; }

AnimatedSprite* SceneObject::getAnimatedSprite() const { return (m_type == Type::Animated) ? m_animatedSprite : nullptr; }

bool SceneObject::isPlayerControlled() const { return m_playerControlled; }

void SceneObject::cllCtrlFunction() {
    if(m_controlFunction) {
        m_controlFunction(*this);
    }
}