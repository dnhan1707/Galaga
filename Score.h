//
// Created by ASUS on 12/8/2023.
//

#ifndef SFML_PROJECT_SCORE_H
#define SFML_PROJECT_SCORE_H

#include "SFML/Graphics.hpp"

class Score : public sf::Drawable
{
private:
    sf::RectangleShape scoreBox;
    int score = 0;
    int highScore;
    int lowScore;


public:
    Score();
    void setSize();


};


#endif //SFML_PROJECT_SCORE_H
