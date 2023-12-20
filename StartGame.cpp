//
// Created by ASUS on 12/19/2023.
//

#include "StartGame.h"

StartGame::StartGame()
: StartGame({700, 500}, Font::getFont(OPEN_SANS))
{

}

StartGame::StartGame(sf::Vector2f screenSize, sf::Font &font)
{
    background.setSize(screenSize);
//    background.setFillColor(sf::Color(0, 0, 0, 150));
    background.setFillColor(sf::Color::White);


    // Configure game over text
    titleText.setFont(font);
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::Black);
    titleText.setString("Welcome To Galaga");

    button.setRadius(50.f);
    button.setUpText("Start!", font);
}

void StartGame::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(titleText);
    window.draw(button);
}

sf::RectangleShape &StartGame::getStartGameBackground() {
    return background;
}

void StartGame::update() {
    button.update();
    if (button.getState(CLICK))
    {
        std::cout << "Here\n";
        enableState(START);
    }
}

void StartGame::setPosition(sf::RectangleShape &background) {
    Position::alignCenter(background, titleText, 0, -50);
    Position::alignCenter(background, button.getButton(), 0, 50);
}

void StartGame::eventHandler(sf::RenderWindow &window, sf::Event event) {
    button.eventHandler(window, event);
}
