//
// Created by ASUS on 11/23/2023.
//

#include "FighterJet.h"


FighterJet::FighterJet()
: FighterJet(Image::getImageFighterJet())
{

}

FighterJet::FighterJet(sf::Texture &image) {
    sf::IntRect intRect;

    intRect.width = image.getSize().x;
    intRect.height = image.getSize().y;

    sprite.setTexture(image);
    sprite.setTextureRect(intRect);

    sprite.setScale(0.1, 0.1);

}

void FighterJet::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(sprite);
}

void FighterJet::move(sf::Vector2f velocity)
{
    sprite.move(velocity);
}

sf::Sprite &FighterJet::getSprite() {
    return sprite;
}
