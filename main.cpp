#include "SFML/Graphics.hpp"
#include "Galaga.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window({1000, 800, 32}, "Galaga");
    window.setFramerateLimit(60);

    Galaga galaga(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                window.close();
            }
//            galaga.eventHandler(window, event);
        }
        galaga.update(window, event);
        window.clear();
        window.draw(galaga);
        window.display();
    }

    return 0;
}
