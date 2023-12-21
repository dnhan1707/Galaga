// FighterJet.h

#ifndef SFML_PROJECT_FIGHTERJET_H
#define SFML_PROJECT_FIGHTERJET_H

#include "SFML/Graphics.hpp"
#include "States.h"
#include "Image.h"
#include "Position.h"
#include "Background.h"
#include "AnimatedSprite.h"

class FighterJet : public States, public sf::Drawable
{
private:
    sf::Sprite jetSprite;
    sf::Sprite explosionSprite;

    sf::Clock clock;
    unsigned int width, height;
    sf::IntRect explosionIntRect;

    void setup(sf::Texture &texture, int rows, int cols);

public:
    FighterJet();

    FighterJet(sf::Texture& jetImage, sf::Texture& explosionImage);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::Sprite& getJetSprite();
    sf::Sprite& getExplosionSprite();
    void move(sf::Vector2f velocity);

    void setPosition();
    sf::Vector2f getPosition();
    void animateExplosion();
    void setupExplosionIntRect(int rows, int cols);
    void setupJet(sf::Texture &texture, int rows, int cols);
    void reset(Background& background);
};

#endif //SFML_PROJECT_FIGHTERJET_H
