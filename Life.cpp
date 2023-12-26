//
// Created by ASUS on 12/21/2023.
//


#include "Life.h"

Life::Life()
: Life(3)
{

}

Life::Life(int numOfLife)
{
    setNumOfLife(numOfLife);
}

void Life::setNumOfLife(int numOfLife)
{
    this->num_of_life = numOfLife;
}

void Life::addLife()
{
    for (int i = 1; i < num_of_life; ++i) {
        FighterJet fighterJet;
//        Position::right(jetLife[i - 1].getJetSprite(), jetLife[i].getJetSprite());
        jetLife.push_back(fighterJet);
    }
//    std::cout << "Crash here\n";
}


void Life::update() {
    if (num_of_life <= 0)
    {
        enableState(OUT_OF_LIFE);
    }
}

void Life::decreaseLife()
{
    jetLife.pop_back();
    num_of_life--;
}

void Life::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto& jetlife : jetLife)
    {
        window.draw(jetlife);
    }
}

void Life::reset()
{
    jetLife.clear();
    num_of_life = 3;
    addLife();
}


std::vector<FighterJet>& Life::getAliens()
{
    return jetLife;
}

void Life::setPosition(Background &background)
{

//    FighterJet fighterJet;
    addLife();
    Position::leftBelowCorner(background.getSprite(), jetLife[0].getJetSprite());
    for (int i = 1; i < num_of_life; ++i) {
//        FighterJet fighterJet;
        Position::right(jetLife[i - 1].getJetSprite(), jetLife[i].getJetSprite());
//        jetLife.push_back(fighterJet);
    }
//    jetLife.push_back(fighterJet);
}
