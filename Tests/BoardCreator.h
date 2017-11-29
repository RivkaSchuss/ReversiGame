//
// Created by Rivka Schuss on 28/11/2017.
//

#ifndef REVERSIGAME_BOARDCREATOR_H
#define REVERSIGAME_BOARDCREATOR_H


#include "../include/Board.h"

class BoardCreator {
public:
    BoardCreator();
    ~BoardCreator();
    Board* board1();
    Board* board2();
    Board* board3();

};


#endif //REVERSIGAME_BOARDCREATOR_H
