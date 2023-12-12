//
// Created by ASUS on 11/23/2023.
//

#include "Background.h"

Background::Background()
{

}

Background::Background(sf::Vector2u windowSize)
:Background(Image::getImageBackground(), windowSize)
{

}

Background::Background(sf::Texture &image, sf::Vector2u windowSize)
{
    sf::IntRect intRect;

    intRect.width = image.getSize().x;
    intRect.height = image.getSize().y;

    sprite.setTexture(image);
    sprite.setTextureRect(intRect);

    sf::Vector2u imageSize = image.getSize();

    float scaleX = (float) (windowSize.x / 1) / imageSize.x;
    float scaleY = (float) (windowSize.y / 1) / imageSize.y;

    sprite.setScale(scaleX, scaleY);

}

void Background::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}

sf::Sprite &Background::getSprite() {
    return sprite;
}

sf::FloatRect Background::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

