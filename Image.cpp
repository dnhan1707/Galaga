//
// Created by ASUS on 11/23/2023.
//

#include "Image.h"


sf::Texture Image::backgroundTexture; // actually create texture

sf::Texture Image::fighterjetTexture;

sf::Texture Image::alienshipTexture;

sf::Texture Image::explosionTexture;


void Image::loadTextureBackground()
{
    backgroundTexture.loadFromFile("background.png");
}

sf::Texture& Image::getImageBackground()
{
    loadTextureBackground();
    return backgroundTexture;
}

void Image::loadTextureFighterJet()
{
    fighterjetTexture.loadFromFile("jetfighter_edited.png");
}

sf::Texture& Image::getImageFighterJet()
{
    loadTextureFighterJet();
    return fighterjetTexture;
}

void Image::loadTextureAlienShip() {
    alienshipTexture.loadFromFile("alienSpaceship.png");
}

sf::Texture &Image::getImageAlienShip()
{
    loadTextureAlienShip();
    return alienshipTexture;
}

void Image::loadTextureExplosion() {
    explosionTexture.loadFromFile("explosion.png");
}

sf::Texture &Image::getImageExplosion() {
    loadTextureExplosion();
    return explosionTexture;
}
