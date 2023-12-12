//
// Created by ASUS on 12/3/2023.
//

#include "Alien.h"

Alien::Alien()
: Alien(Image::getImageAlienShip(), Image::getImageExplosion())  // Initialize with alien and explosion textures
{
    // ...
}


Alien::Alien(sf::Texture& alienTexture, sf::Texture& explosionTexture)
: explosionSprite(explosionTexture, 6, 8)  // Initialize explosion sprite
{
    sf::IntRect intRect;

    intRect.width = alienTexture.getSize().x;
    intRect.height = alienTexture.getSize().y;

    sprite.setTexture(alienTexture);
    sprite.setTextureRect(intRect);

    sprite.setScale(0.009, 0.009);
}

void Alien::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (isExploding) {
        window.draw(explosionSprite);
    } else {
        window.draw(sprite);
    }
}


sf::Sprite & Alien::getSprite()
{
    return sprite;
}


void Alien::move(sf::Vector2f velocity)
{
    sprite.move(velocity);
}

void Alien::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Alien::setRandPosition()
{

    int rand_x = rand() % (830 - 166 + 1) + 166;
    int rand_y = rand() % (300 - 133 + 1) + 133;
    sprite.setPosition(rand_x,rand_y);

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

void Alien::onHit()
{
    if (!isExploding)
    {
        std::cout << "Here\n";
        isExploding = true;
        explosionSprite.setPosition(sprite.getPosition());
        explosionSprite.animate();
    }
}


void Alien::update()
{
    if (isExploding) {
        explosionSprite.animate();
        if (explosionSprite.getGlobalBounds().width <= 0) {
            // Reset to initial state after the explosion is complete
            isExploding = false;
            explosionSprite.reset();
        }
    }
}


void Alien::updateExplosionAnimation() {
    explosionSprite.animate();
}

bool Alien::isExplosionComplete() {
    return explosionSprite.isExplosionComplete();
}

void Alien::reset() {
    explosionSprite.reset();
}

