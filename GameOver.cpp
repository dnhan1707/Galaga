//
// Created by ASUS on 12/7/2023.
//

#include "GameOver.h"

GameOver::GameOver()
: GameOver({300, 300}, Font::getFont(OPEN_SANS))
{

}

GameOver::GameOver(sf::Vector2f screenSize, sf::Font &font)
{
    // Configure background
    background.setSize(screenSize);
//    background.setFillColor(sf::Color(0, 0, 0, 150));
    background.setFillColor(sf::Color::White);


    // Configure game over text
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setString("You Lost!");

    // Configure longest survival time text
    longestSurvivalText.setFont(font);
    longestSurvivalText.setCharacterSize(30);
    longestSurvivalText.setFillColor(sf::Color::Black);

    // Configure restart text
    restartText.setFont(font);
    restartText.setCharacterSize(30);
    restartText.setFillColor(sf::Color::Black);
    restartText.setString("Restart");


    button.setRadius(50.f);
    button.setUpText("Restart", font);
}

void GameOver::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(gameOverText);
    window.draw(longestSurvivalText);
    window.draw(button);
}

void GameOver::setLongestSurvivalTime(const std::string &time) {
    longestSurvivalText.setString("Longest Survival Time: " + time);
}

sf::RectangleShape &GameOver::getGameOverBackground() {
    return background;
}

void GameOver::update() {
    if (getState(LOSE))
    {

    }
}

void GameOver::setPosition(sf::RectangleShape& background)
{
//    longestSurvivalText.setPosition(screenSize.x / 2 - longestSurvivalText.getGlobalBounds().width / 2, screenSize.y / 2);
//    restartText.setPosition(screenSize.x / 2 - restartText.getGlobalBounds().width / 2, 3 * screenSize.y / 4);
    Position::alignCenter(background, gameOverText, 0, -50);
    Position::alignCenter(background, button.getButton(), 0, 50);
}



