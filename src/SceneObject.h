#pragma once

#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class SceneObject {
public:
    enum class Type {
        Static,
        Animated

    };

    using ControlFunction = void(*)(SceneObject&);

    SceneObject(sf::Sprite* sprite, bool playerControlled, ControlFunction controlFunction = nullptr);
    SceneObject(AnimatedSprite* animatedSprite, bool playerControlled, ControlFunction controlFunction = nullptr);
    Type getType() const;
    sf::Sprite* getSprite() const;
    AnimatedSprite* getAnimatedSprite() const;
    bool isPlayerControlled() const;
    void cllCtrlFunction();
private:
    Type m_type;
    union {
        sf::Sprite* m_sprite;
        AnimatedSprite* m_animatedSprite;
    };
    bool m_playerControlled;
    ControlFunction m_controlFunction;
};