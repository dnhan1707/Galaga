//
// Created by ASUS on 11/14/2023.
//

#include "Display.h"

Display::Display() //TODO after Fonts class is created
:Display({200, 200}, Font::getFont(OPEN_SANS), 24)
{

}

Display::Display(sf::Vector2f size, sf::Font& font, unsigned int characterSize)
: Display(size, font, characterSize, sf::Color::Black, { 0, 0 }, 9, true)  // Enable time tracking
{
}


Display::Display(sf::Vector2f size, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit, bool trackTime)
{
    setSize(size);
    setFont(font);
    setCharacterSize(characterSize);
    setColor(color);
    setPosition(position);
}

void Display::show() {

    disableState(HIDDEN);
}

void Display::clear() {
    text.setString("");
}

void Display::setText(const std::string &text) {
    Position::centerText(box, this->text);

    this->text.setString(text);
}

std::string Display::getText() {
    return text.getString();

}

void Display::setCharacterLimit(int limits) {
    this->limit = limits;
}

void Display::setColor(sf::Color color) {
    this->box.setFillColor(color);
}

void Display::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void Display::setSize(sf::Vector2f size) {
    this->box.setSize(size);
}

void Display::setPosition(sf::Vector2f position) {
    this->box.setPosition(position);
}

void Display::setCharacterSize(unsigned int size) {
    this->text.setCharacterSize(size);
}

void Display::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(box);
    window.draw(text);
}

sf::RectangleShape &Display::getDisplayBox() {
    return this->box;
}

void Display::setTextPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

sf::Text& Display::getTextObject()
{
    return text;
}


void Display::update() {
    // Update the text with the elapsed time
    setText(getElapsedTimeAsString());
}


std::string Display::getElapsedTimeAsString() {
    // Get elapsed time in seconds
    float elapsedSeconds = clock.getElapsedTime().asSeconds();

    // Format elapsed time as a string (minutes:seconds)
    int minutes = static_cast<int>(elapsedSeconds) / 60;
    int seconds = static_cast<int>(elapsedSeconds) % 60;

    return "Time: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}