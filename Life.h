//
// Created by ASUS on 12/21/2023.
//

#ifndef SFML_PROJECT_LIFE_H
#define SFML_PROJECT_LIFE_H

#include "SFML/Graphics.hpp"
#include "States.h"
#include "vector"
#include "FighterJet.h"
#include "Background.h"
#include "Position.h"

class Life : public sf::Drawable, public States
{
private:
    int num_of_life;
    std::vector<FighterJet> jetLife;

public:
    Life();
    Life(int numOfLife);
    void setNumOfLife(int numOfLife);
    void addLife();
    void update();
    void decreaseLife();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void reset();
    std::vector<FighterJet>& getAliens();
    void setPosition(Background& background);
};

#endif //SFML_PROJECT_LIFE_H
