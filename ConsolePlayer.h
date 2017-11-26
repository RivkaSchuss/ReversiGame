//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_CONSOLEPLAYER_H
#define ASSIGNMENT1_CONSOLEPLAYER_H

#include "AbstractPlayer.h"

class ConsolePlayer: public AbstractPlayer {

public:
    ConsolePlayer(Type type);
    ~ConsolePlayer();
    void performMove(Location* moves, Board* board, GameLogic* logic);
    PlayerType getPType();
private:
    //the members of the class:
    Type type;
    PlayerType pType;
};


#endif //ASSIGNMENT1_CONSOLEPLAYER_H
