//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_PLAYER_H
#define ASSIGNMENT1_PLAYER_H

#include "Board.h"
#include "GameLogic.h"

enum PlayerType {Console, AI};

class Player{

public:
    virtual void performMove(Location* moves, Board* board, GameLogic* logic) = 0;
    virtual PlayerType getPType() = 0;
private:
    //the members of the class:
    Type type;
    PlayerType pType;
};


#endif //ASSIGNMENT1_PLAYER_H
