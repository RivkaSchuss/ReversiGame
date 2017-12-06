//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_PLAYER_H
#define ASSIGNMENT1_PLAYER_H

#include "Board.h"
#include "GameLogic.h"
#include "Server.h"
#include <vector>

using namespace std;

enum PlayerType {Console, AI, Remote};

class Player{

public:
    virtual void performMove(vector<Location> moves, Board* board, GameLogic* logic) = 0;
    virtual PlayerType getPType() = 0;
    //virtual Server* getServer() = 0;
private:
    //the members of the class:
    Type type;
    PlayerType pType;
};


#endif //ASSIGNMENT1_PLAYER_H
