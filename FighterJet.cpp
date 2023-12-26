//
// Created by ASUS on 11/23/2023.
//

#include "FighterJet.h"
#include "AnimatedSprite.h"

FighterJet::FighterJet()
: FighterJet(Image::getImageFighterJet(), Image::getImageExplosion())
{
}

FighterJet::FighterJet(sf::Texture& jetImage, sf::Texture& explosionImage)
{
    setupJet(jetImage, 1, 1);
    setup(explosionImage, 6, 8);

}

void FighterJet::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    if (getState(HIT))
    {
        window.draw(explosionSprite);
    }
    else
        window.draw(jetSprite);

}

void FighterJet::move(sf::Vector2f velocity)
{
    jetSprite.move(velocity);
    explosionSprite.move(velocity);
}

sf::Sprite &FighterJet::getJetSprite(){
    return jetSprite;
}

sf::Sprite &FighterJet::getExplosionSprite()
{
    return explosionSprite;
}

void FighterJet::animateExplosion()
{
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        if (explosionIntRect.left + explosionIntRect.width >= width)
        {
            explosionIntRect.left = 0;
            explosionIntRect.top += explosionIntRect.height;
            if (explosionIntRect.top + explosionIntRect.height >= height)
            {
                explosionIntRect.top = 0;
                enableState(LOSE);
                disableState(HIT);
            }
        }
        else
        {
            explosionIntRect.left += explosionIntRect.width;
        }
        clock.restart();

        // Use the explosion sprite's setTextureRect instead of FighterJet's setTextureRect
        explosionSprite.setTextureRect(explosionIntRect);
    }
}

void FighterJet::setup(sf::Texture &texture, int rows, int cols)
{
    width = texture.getSize().x;
    height = texture.getSize().y;
    explosionSprite.setTexture(texture);
    setupExplosionIntRect(rows, cols);
}

void FighterJet::setupExplosionIntRect(int rows, int cols)
{
    explosionIntRect.width = width / cols;
    explosionIntRect.height = height / rows;

    explosionIntRect.left = 0;
    explosionIntRect.top = 0;
    explosionSprite.setTextureRect(explosionIntRect);
}


void FighterJet::setupJet(sf::Texture &texture, int rows, int cols)
{
    sf::IntRect intRect;

    intRect.width = texture.getSize().x;
    intRect.height = texture.getSize().y;

    jetSprite.setTexture(texture);
    jetSprite.setTextureRect(intRect);

    jetSprite.setScale(0.1, 0.1);

}

void FighterJet::reset(Background& background)
{
    disableState(HIT);
    disableState(LOSE);

    Position::alignCenter(background.getSprite(), getJetSprite(), 0, 200);
    Position::alignCenter(background.getSprite(), getExplosionSprite(), 0, 200);
}

