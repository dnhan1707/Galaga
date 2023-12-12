//
// Created by ASUS on 12/5/2023.
//

#ifndef SFML_PROJECT_ALIENSHIP_H
#define SFML_PROJECT_ALIENSHIP_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "FighterJet.h"
#include "Alien.h"
#include "AnimatedSprite.h"
#include "Image.h"

class AlienShip : public sf::Drawable
{

private:
    std::vector<Alien> aliens;

public:
    AlienShip();
    void update();
    void addAlien();
    std::vector<Alien>& getAliens();
    void move();  // Add a move method for AlienShip
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_PROJECT_ALIENSHIP_H
