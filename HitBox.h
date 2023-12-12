//
// Created by ASUS on 12/5/2023.
//

#ifndef SFML_PROJECT_HITBOX_H
#define SFML_PROJECT_HITBOX_H

#include "SFML/Graphics.hpp"
class HitBox
{
public:
    template<typename T, typename S>
    static bool isHit(const T& constObject, S& object);

    template<typename T, typename S>
    static bool isHitFromTop(const T& constObject, S& object);

    template<typename T, typename S>
    static bool isHitFromLeft(const T& constObject, S& object);

    template<typename T, typename S>
    static bool isHitFromRight(const T& constObject, S& object);

    template<typename T, typename S>
    static bool isHitFromBottom(const T& constObject, S& object);

};

#include "HitBox.cpp"

#endif //SFML_PROJECT_HITBOX_H
