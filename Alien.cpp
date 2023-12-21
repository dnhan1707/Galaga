//
// Created by ASUS on 12/3/2023.
//

#include "Alien.h"

Alien::Alien()
: Alien(Image::getImageAlienShip(), Image::getImageExplosion())  // Initialize with alien and explosion textures
{

}


Alien::Alien(sf::Texture& alienTexture, sf::Texture& explosionTexture)
{

    setup(explosionTexture, 6, 8);
    setupAlien(alienTexture, 1 , 1);

}

void Alien::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (getState(HIT) && !getState(DONE_ANIMATING)) {
        window.draw(explosionSprite);
    }
    else {
        window.draw(sprite);
    }
}


sf::Sprite & Alien::getSprite()
{
    return sprite;
}

sf::Sprite & Alien::getExplosionSprite()
{
    return explosionSprite;
}


void Alien::move(sf::Vector2f velocity)
{

    sprite.move(velocity);
    explosionSprite.move(velocity);
}

void Alien::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
    explosionSprite.setPosition(position);

}

void Alien::setRandPosition()
{

    int rand_x = rand() % (830 - 166 + 1) + 166;
    int rand_y = rand() % (300 - 133 + 1) + 133;
    sprite.setPosition(rand_x,rand_y);
    explosionSprite.setPosition(rand_x, rand_y);

}

sf::Vector2f Alien::getPosition() {
    return sprite.getPosition();
}

void Alien::bounce()
{

    if (firstMove)
    {
        start_x = (rand() % 5) + 1;
        start_y = (rand() % 5) + 1;
        move({start_x, start_y});
        firstMove = false;
    }

    if (getPosition().x >= 770 || getPosition().x <= 166)
    {
        start_x *= -1;
    }
    if (getPosition().y >= 640 || getPosition().y <= 133)
    {
        start_y *= -1;
    }

    move({start_x, start_y});

}


void Alien::animateExplosion() {
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        if (explosionIntRect.left + explosionIntRect.width >= width)
        {
            explosionIntRect.left = 0;
            explosionIntRect.top += explosionIntRect.height;
            if (explosionIntRect.top + explosionIntRect.height >= height)
            {
                explosionIntRect.top = 0;
                enableState(DONE_ANIMATING);
            }
        }
        else
        {
            explosionIntRect.left += explosionIntRect.width;
            clock.restart();

            explosionSprite.setScale(0.5, 0.5);
            explosionSprite.setTextureRect(explosionIntRect);
        }

    }
}

void Alien::setupExplosionIntRect(int rows, int cols) {
    explosionIntRect.width = width / cols;
    explosionIntRect.height = height / rows;

    explosionIntRect.left = 0;
    explosionIntRect.top = 0;
    explosionSprite.setTextureRect(explosionIntRect);
}

void Alien::setupAlien(sf::Texture &texture, int rows, int cols) {
    sf::IntRect intRect;

    intRect.width = texture.getSize().x;
    intRect.height = texture.getSize().y;

    sprite.setTexture(texture);
    sprite.setTextureRect(intRect);

    sprite.setScale(0.009, 0.009);
}

void Alien::setup(sf::Texture &texture, int rows, int cols) {
    width = texture.getSize().x;
    height = texture.getSize().y;
    explosionSprite.setTexture(texture);

    setupExplosionIntRect(rows, cols);
}

bool Alien::isExplosionComplete() const {
    return (explosionIntRect.left + explosionIntRect.width >= width) &&
           (explosionIntRect.top + explosionIntRect.height >= height);
}

void Alien::reset() {
    clock.restart();
    firstMove = true;
    disableState(DONE_ANIMATING);
}




