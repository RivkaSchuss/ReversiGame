//
// Created by Rivka Schuss on 22/11/2017.
//

#ifndef ASSIGNMENT1_AIPLAYER_H
#define ASSIGNMENT1_AIPLAYER_H


#include "AbstractPlayer.h"

class AIPlayer : public AbstractPlayer {
public:
    AIPlayer(Type type);
    ~AIPlayer();
    void performMove(Location* moves, Board* board, GameLogic* logic);
private:
    Type type;

};


#endif //ASSIGNMENT1_AIPLAYER_H
