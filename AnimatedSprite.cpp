//
// Created by ASUS on 12/7/2023.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
: AnimatedSprite(Image::getImageExplosion(), 6, 8)
{

}

AnimatedSprite::AnimatedSprite(sf::Texture &texture, int rows, int cols)
{
    setup(texture, rows, cols);
}

void AnimatedSprite::setup(sf::Texture &texture, int rows, int cols) {
    width = texture.getSize().x;
    height = texture.getSize().y;
    setTexture(texture);
    setupIntRect(rows, cols);
}


void AnimatedSprite::setupIntRect(int rows, int cols) {
    intRect.width = width / cols;
    intRect.height = height / rows;

    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}


void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite s = (*this);
    target.draw(s);
}

void AnimatedSprite::animate()
{
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        if (intRect.left + intRect.width >= width)
        {

            intRect.left = 0;
            intRect.top += intRect.height;
            if (intRect.top + intRect.height >= height)
            {
                intRect.top = 0;
            }
        }
        else
        {
            intRect.left += intRect.width;
        }
        clock.restart();
        setTextureRect(intRect);
    }
}
// Add this method to the AnimatedSprite class
void AnimatedSprite::reset()
{
    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}

bool AnimatedSprite::isExplosionComplete() {
    // Check if the explosion animation is complete
    return intRect.left + intRect.width >= width && intRect.top + intRect.height >= height;
}