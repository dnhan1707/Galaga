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
    AnimatedSprite explosionSprite;  // Add AnimatedSprite for explosion
    bool isExploding = false;        // Flag to track if explosion is happening
    float start_x, start_y;
    bool firstMove = true;

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
    void onHit();  // Method to trigger explosion

    // Update method to handle explosion animation
    void update();


    // Function to start the explosion animation
    void updateExplosionAnimation();

    // Function to check if the explosion animation is complete
    bool isExplosionComplete();

    // Function to reset the alien to its initial state
    void reset();
};

#endif //SFML_PROJECT_ALIEN_H
