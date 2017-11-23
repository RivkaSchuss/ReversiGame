//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_ABSTRACTPLAYER_H
#define ASSIGNMENT1_ABSTRACTPLAYER_H

#include "Location.h"
#include "Player.h"

class AbstractPlayer : public Player {
public:
    AbstractPlayer(Type type);
    ~AbstractPlayer();
    virtual void performMove(Location* moves, Board* board, GameLogic* logic) = 0;
private:
    //the members of the class
    Type type;
};


#endif //ASSIGNMENT1_ABSTRACTPLAYER_H
