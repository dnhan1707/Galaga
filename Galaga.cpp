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

    Position::alignCenter(background.getSprite(), startGameWindow.getStartGameBackground(), 0, 0);
    startGameWindow.setPosition(startGameWindow.getStartGameBackground());

//    life.setPosition(background);

    Position::alignCenter(background.getSprite(), gameOver.getGameOverBackground(), 0, 0);
    gameOver.setPosition(gameOver.getGameOverBackground());

}

void Galaga::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!isOver && start)
    {
        window.draw(background);
        window.draw(fighterJet);
        window.draw(alienShip);
        window.draw(gun);
        window.draw(display);
//        window.draw(life);
    }

//    if (fighterJet.getState(LOSE) && life.getState(OUT_OF_LIFE))
    if (fighterJet.getState(LOSE))
    {
        window.draw(gameOver);
        isOver = true;
    }

    if (!start)
    {
        window.draw(startGameWindow);
    }

}

void Galaga::update(sf::RenderWindow &window, sf::Event event)
{
    if (!startGameWindow.getState(START))
    {
        enableStartWindow();
//        startGameWindow.disableState(START);
    }

    if (gameOver.getState(RESTART))
    {
        resetGame();
        gameOver.disableState(RESTART);
    }

    if (!fighterJet.getState(HIT) && start)
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
        gameOver.update(fighterJet);

//        life.decreaseLife();
//        if (life.getState(OUT_OF_LIFE))
//        {
//            gameOver.update(fighterJet);
//        }
    }

//    life.update();

}

void Galaga::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    startGameWindow.eventHandler(window, event);
    if (startGameWindow.getState(START))
    {
        start = true;
    }

//    if (life.getState(OUT_OF_LIFE))
//    {
        gameOver.eventHandler(window, event);
//    }
}

void Galaga::resetGame() {
//    life.reset();
    gun.reset();
    fighterJet.reset(background);
    alienShip.reset();

    clock.restart();
    isOver = false;
    gameOver.disableState(GAME_OVER_STATE);

}

void Galaga::enableStartWindow()
{
    start = false;
}
