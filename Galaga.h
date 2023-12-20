//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_GALAGA_H
#define SFML_PROJECT_GALAGA_H

#include "SFML/Graphics.hpp"
#include "Background.h"
#include "FighterJet.h"
#include "Position.h"
#include "Rocket.h"
#include "Gun.h"
#include "vector"
#include "AlienShip.h"
#include "HitBox.h"
#include "Display.h"
#include "AnimatedSprite.h"
#include "GameOver.h"
#include "StartGame.h"

class Galaga : public sf::Drawable, public States
{
private:
    FighterJet fighterJet;
    Background background;
    Display display;

    sf::Clock clock;

    AlienShip alienShip;
    Gun gun;
    GameOver gameOver;
    StartGame startGame;

    AnimatedSprite animatedSprite;

    bool isOver = false;
public:
    Galaga();
    Galaga(sf::RenderWindow& window);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update(sf::RenderWindow& window, sf::Event event);

    void eventHandler(sf::RenderWindow &window, sf::Event event);

};


#endif //SFML_PROJECT_GALAGA_H
