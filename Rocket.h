//
// Created by ASUS on 11/30/2023.
//

#ifndef SFML_PROJECT_ROCKET_H
#define SFML_PROJECT_ROCKET_H

#include "SFML/Graphics.hpp"
#include "States.h"

class Rocket : public sf::Drawable, public States
{
private:
    sf::RectangleShape rocket;
    sf::FloatRect hitbox;

public:
    Rocket();
    Rocket(sf::Vector2f size, sf::Color color);

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition();

    void setColor(sf::Color color);
    void move(sf::Vector2f velocity);

    void clear();
    sf::RectangleShape& getRocket();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    template<typename T>
    bool outOfBounds(const T& constObj);
    void updateHitbox();

};


#endif //SFML_PROJECT_ROCKET_H
