//
// Created by ASUS on 12/7/2023.
//

#ifndef SFML_PROJECT_ANIMATEDSPRITE_H
#define SFML_PROJECT_ANIMATEDSPRITE_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include "States.h"
#include "Image.h"
class AnimatedSprite : public sf::Sprite
{
private:
    sf::Clock clock;
    unsigned int width, height;
    sf::IntRect intRect;

    void setup(sf::Texture &texture, int rows, int cols);

public:
    AnimatedSprite();
    AnimatedSprite(sf::Texture &texture, int rows, int cols);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void animate(sf::Vector2f position);
    void reset();

    void setupIntRect(int rows, int cols);
    bool isExplosionComplete();
};


#endif //SFML_PROJECT_ANIMATEDSPRITE_H
