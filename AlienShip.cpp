//
// Created by ASUS on 12/5/2023.
//

#include "AlienShip.h"

AlienShip::AlienShip()
{

}

void AlienShip::update()
{
    for (auto& alien : aliens)
    {
        alien.bounce();
        // Handle collisions or other events if needed
    }
}


void AlienShip::addAlien()
{
    for (int i = 0; i < 5; ++i) {
        Alien newAlienShip;
        newAlienShip.setRandPosition();
        aliens.push_back(newAlienShip);
    }
}

void AlienShip::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto& alien : aliens)
    {
        window.draw(alien);
    }

}


std::vector<Alien>& AlienShip::getAliens()
{
    return aliens;
}
