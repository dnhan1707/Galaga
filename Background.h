//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_BACKGROUND_H
#define SFML_PROJECT_BACKGROUND_H

#include "SFML/Graphics.hpp"
#include "Image.h"
#include "Position.h"

class Background : public sf::Drawable
{
public:
    Background();
    Background(sf::Vector2u windowSize);
    Background(sf::Texture& image, sf::Vector2u windowSize);

    sf::Sprite& getSprite();

    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:

    sf::Sprite sprite;
};


#endif //SFML_PROJECT_BACKGROUND_H
