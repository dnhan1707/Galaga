//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_IMAGE_H
#define SFML_PROJECT_IMAGE_H

#include "SFML/Graphics.hpp"


class Image {
private:
    static sf::Texture backgroundTexture;
    static sf::Texture fighterjetTexture;
    static sf::Texture alienshipTexture;
    static sf::Texture explosionTexture;
    static unsigned int width, height;

    static void loadTextureBackground();
    static void loadTextureFighterJet();
    static void loadTextureAlienShip();
    static void loadTextureExplosion();




public:
    static sf::Texture& getImageBackground();
    static sf::Texture& getImageFighterJet();
    static sf::Texture& getImageAlienShip();
    static sf::Texture& getImageExplosion();

};


#endif //SFML_PROJECT_IMAGE_H
