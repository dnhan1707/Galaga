//
// Created by ASUS on 12/5/2023.
//

#ifndef SFML_PROJECT_HITBOX_CPP
#define SFML_PROJECT_HITBOX_CPP

#include "HitBox.h"


template<typename T, typename S>
bool HitBox::isHit(const T &constObject, S &object)
{
    sf::FloatRect objectBounds = object.getGlobalBounds();
    sf::FloatRect obstacleBounds = constObject.getGlobalBounds();

    return objectBounds.intersects(obstacleBounds);

}


template<typename T, typename S>
bool HitBox::isHitFromTop(const T& constObject, S& object)
{
    sf::FloatRect cb = constObject.getGlobalBounds();
    sf::FloatRect ob = object.getGlobalBounds();

    if (ob.top + ob.height == cb.top)
    {
        return true;
    }
    return false;
}

template<typename T, typename S>
bool HitBox::isHitFromLeft(const T& constObject, S& object)
{
    sf::FloatRect cb = constObject.getGlobalBounds();
    sf::FloatRect ob = object.getGlobalBounds();

    if (ob.left + ob.width == cb.left)
    {
        return true;
    }
    return false;
}

template<typename T, typename S>
bool HitBox::isHitFromRight(const T& constObject, S& object)
{
    sf::FloatRect cb = constObject.getGlobalBounds();
    sf::FloatRect ob = object.getGlobalBounds();

    if(ob.left == cb.left + cb.width)
    {
        return true;
    }
    return false;
}

template<typename T, typename S>
bool HitBox::isHitFromBottom(const T& constObject, S& object)
{
    sf::FloatRect cb = constObject.getGlobalBounds();
    sf::FloatRect ob = object.getGlobalBounds();

    if (ob.top == cb.top + cb.height)
    {
        return true;
    }

    return false;
}


#endif