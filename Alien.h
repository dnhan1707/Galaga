//
// Created by ASUS on 12/3/2023.
//

#ifndef SFML_PROJECT_ALIEN_H
#define SFML_PROJECT_ALIEN_H

#include "SFML/Graphics.hpp"
#include "States.h"
#include "Image.h"
#include "Background.h"
#include "vector"
#include "HitBox.h"
#include "FighterJet.h"
#include "AnimatedSprite.h"

class Alien : public sf::Drawable, public States
{
private:
    sf::Sprite sprite;
    sf::Sprite explosionSprite;

    sf::Clock clock;
    unsigned int width, height;
    sf::IntRect explosionIntRect;

    float start_x, start_y;
    bool firstMove = true;

    void setup(sf::Texture &texture, int rows, int cols);

public:
    Alien();
    Alien(sf::Texture& alienTexture, sf::Texture& explosionTexture);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::Sprite & getSprite();
    void move(sf::Vector2f velocity);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void setRandPosition();

    void bounce();
    sf::Sprite &getExplosionSprite();

    void setupExplosionIntRect(int rows, int cols);
    void setupAlien(sf::Texture &texture, int rows, int cols);
    void animateExplosion();
};

#endif //SFML_PROJECT_ALIEN_H
