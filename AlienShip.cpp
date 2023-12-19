//
// Created by ASUS on 12/5/2023.
//

#include "AlienShip.h"

AlienShip::AlienShip()
{

}

void AlienShip::update() {
    auto removeIter = std::remove_if(aliens.begin(), aliens.end(), [](const Alien& alien) {
        return alien.getState(DONE_ANIMATING);
    });

    aliens.erase(removeIter, aliens.end());

    for (auto& alien : aliens) {
        if (!alien.getState(HIT) && !alien.getState(DONE_ANIMATING)) {
            alien.bounce();
        } else if (!alien.getState(DONE_ANIMATING)) {
            alien.animateExplosion();
        }
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

