//
// Created by ASUS on 12/19/2023.
//

#ifndef SFML_PROJECT_STARTGAME_H
#define SFML_PROJECT_STARTGAME_H

#include "SFML/Graphics.hpp"
#include "Font.h"
#include "Button.h"
#include "Background.h"
#include "States.h"

class StartGame : public sf::Drawable, public States
{
private:
    sf::RectangleShape background;
    sf::Text titleText;
    sf::Text startText;
    Button button;
public:
    StartGame();
    StartGame(sf::Vector2f screenSize, sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::RectangleShape& getStartGameBackground();
    void update();
    void setPosition(sf::RectangleShape& background);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
};


#endif //SFML_PROJECT_STARTGAME_H
