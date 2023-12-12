//
// Created by ASUS on 11/30/2023.
//

#include "Rocket.h"

Rocket::Rocket()
: Rocket({50, 90}, sf::Color::Red)
{

}

Rocket::Rocket(sf::Vector2f size, sf::Color color)
{
    setSize(size);
    setColor(color);
}

void Rocket::setSize(sf::Vector2f size) {
    rocket.setSize(size);
}

void Rocket::setPosition(sf::Vector2f position) {
    rocket.setPosition(position);
}

void Rocket::setColor(sf::Color color) {
    rocket.setFillColor(color);
}

sf::RectangleShape &Rocket::getRocket()
{
    return rocket;
}

void Rocket::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(rocket);
}

void Rocket::move(sf::Vector2f velocity) {
    rocket.move(velocity);
}

sf::Vector2f Rocket::getPosition()
{
    return rocket.getPosition();
}

void Rocket::update()
{

}

void Rocket::clear()
{

}

template <typename T>
bool Rocket::outOfBounds(const T& constObj)
{
    sf::Vector2f cb = constObj.getPosition();
    sf::Vector2f ob = getPosition();

    return ob.y <= cb.y;
}

void Rocket::updateHitbox()
{
    hitbox = rocket.getGlobalBounds();
}