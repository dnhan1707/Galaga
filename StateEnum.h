//
// Created by ASUS on 11/16/2023.
//

#ifndef SFML_PROJECT_STATEENUM_H
#define SFML_PROJECT_STATEENUM_H


enum StateEnum {
    HIDDEN, HIT, FIRE, FIRED, CLICK, RESTART, DONE_ANIMATING, LOSE, START, GAME_OVER_STATE, OUT_OF_LIFE,

    /// Do not add state below this line
    LAST_STATE
};

#endif //SFML_PROJECT_STATEENUM_H
