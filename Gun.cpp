//
// Created by ASUS on 11/30/2023.
//

#include "Gun.h"

Gun::Gun()
{

}

void Gun::shoot(FighterJet& jet, Background& background, AlienShip& alienShip)
{
    if (clock.getElapsedTime().asSeconds() >= 1.5)
    {
        // Create new rocket
        Rocket newRocket;
        newRocket.setSize({5, 9});
        Position::aboveAndMiddle(jet.getSprite(), newRocket.getRocket());
        rockets.push_back(newRocket);
        clock.restart();
    }

    for (auto rocketIt = rockets.begin(); rocketIt != rockets.end();)
    {
        bool rocketRemoved = false;

        auto alienIt = alienShip.getAliens().begin();
        while (alienIt != alienShip.getAliens().end())
        {

            // Check collision between jet and alien ship
            if (HitBox::isHit(jet.getSprite(), alienIt->getSprite()))
            {
                // Handle collision
                jet.enableState(HIT);
                std::cout << "Jet was hit\n";
                break;
            }

            // Check collision between rocket and alien ship
            if (HitBox::isHit(rocketIt->getRocket(), alienIt->getSprite()))
            {
                // Handle collision
//                animate();
                rocketIt = rockets.erase(rocketIt);
                rocketRemoved = true;
                alienIt = alienShip.getAliens().erase(alienIt);
                break; // Break the inner loop since the rocket is removed
            }
            else
            {
                ++alienIt;
            }
        }

        if (rocketIt != rockets.end())
        {
            // Check if the rocket is not removed, then move it
            if (!rocketRemoved)
            {
                if (rocketIt->getPosition().y <= background.getSprite().getPosition().y)
                {
                    rocketIt = rockets.erase(rocketIt);
                }
                else
                {
                    rocketIt->move({0, -1});
                    ++rocketIt;
                }
            }
        }
    }
}


std::vector<Rocket>& Gun::getRocketsVector()
{
    return rockets;
}


void Gun::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto& rocket : rockets)
    {
        window.draw(rocket);
    }

}

