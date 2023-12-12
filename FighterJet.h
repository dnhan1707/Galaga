//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_FIGHTERJET_H
#define SFML_PROJECT_FIGHTERJET_H

#include "SFML/Graphics.hpp"
#include "States.h"
#include "Image.h"
#include "Position.h"
#include "Background.h"

class FighterJet : public sf::Drawable, public States
{
private:
    sf::Sprite sprite;
public:
    FighterJet();
    FighterJet(sf::Texture& image);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::Sprite& getSprite();
    void move(sf::Vector2f velocity);
};


#endif //SFML_PROJECT_FIGHTERJET_H
