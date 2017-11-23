//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_PLAYER_H
#define ASSIGNMENT1_PLAYER_H

#include "Board.h"
#include "GameLogic.h"


class Player{

public:
    virtual void performMove(Location* moves, Board* board, GameLogic* logic) = 0;
private:
    //the members of the class:
    Type type;
};


#endif //ASSIGNMENT1_PLAYER_H
