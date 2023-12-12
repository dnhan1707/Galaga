//
// Created by ASUS on 11/30/2023.
//

#ifndef SFML_PROJECT_GUN_H
#define SFML_PROJECT_GUN_H

#include "SFML/Graphics.hpp"
#include "Rocket.h"
#include "vector"
#include "States.h"
#include "Position.h"
#include "FighterJet.h"
#include "Background.h"
#include "HitBox.h"
#include "AlienShip.h"
#include "AnimatedSprite.h"

class Gun : public AnimatedSprite, public States
{
private:
    std::vector<Rocket> rockets;
    sf::Clock clock;

public:
    Gun();

    void shoot(FighterJet& jet, Background& background, AlienShip& alienShip);
    std::vector<Rocket>& getRocketsVector();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update(AlienShip& alienShip);

};


#endif //SFML_PROJECT_GUN_H
