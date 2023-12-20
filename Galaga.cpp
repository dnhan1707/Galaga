//
// Created by ASUS on 11/23/2023.
//

#include "Galaga.h"

Galaga::Galaga()
{

}

Galaga::Galaga(sf::RenderWindow& window)
:background(window.getSize())
{

    Position::centerWithWindow(window, background.getSprite());
    Position::alignCenter(background.getSprite(), fighterJet.getJetSprite(), 0, 200);
    Position::alignCenter(background.getSprite(), fighterJet.getExplosionSprite(), 0, 200);


    display.setSize({80, 60});
    display.setCharacterSize(15);
    display.setColor(sf::Color{28, 28, 28});
    Position::alignLeft(background.getSprite(), display);

    alienShip.addAlien();
//    Position::alignCenter(background.getSprite(), startGame.getStartGameBackground(), 0, 0);

    Position::alignCenter(background.getSprite(), gameOver.getGameOverBackground(), 0, 0);
//    startGame.setPosition(startGame.getStartGameBackground());
    gameOver.setPosition(gameOver.getGameOverBackground());

}

void Galaga::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
//    if (!startGame.getState(START))
//    {
//        window.draw(startGame);
//    }
//
//    else if (startGame.getState(START))
//    {
        window.draw(background);
        window.draw(fighterJet);
        window.draw(alienShip);
        window.draw(gun);
        window.draw(display);
//    }


    if (fighterJet.getState(LOSE))
    {
        window.draw(gameOver);
    }
}

void Galaga::update(sf::RenderWindow &window, sf::Event event)
{
    if (!fighterJet.getState(HIT))
    {
        // Update game logic, e.g., movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            fighterJet.move({-5, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            fighterJet.move({0, -5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            fighterJet.move({0, 5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            fighterJet.move({5, 0});
        }

        alienShip.update();
        gun.shoot(fighterJet, background, alienShip);
        display.update();
    }
    else
    {
        fighterJet.animateExplosion();
    }

    gameOver.update();

}

void Galaga::eventHandler(sf::RenderWindow &window, sf::Event event)
{
//    startGame.eventHandler(window,event);
    gameOver.eventHandler(window, event);
}