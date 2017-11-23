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

private:
    //the members of the class:
    Type type;
};


#endif //ASSIGNMENT1_CONSOLEPLAYER_H
