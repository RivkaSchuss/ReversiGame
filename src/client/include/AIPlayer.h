//
// Created by Rivka Schuss on 22/11/2017.
//

#ifndef ASSIGNMENT1_AIPLAYER_H
#define ASSIGNMENT1_AIPLAYER_H


#include "AbstractPlayer.h"
#include <vector>

using namespace std;

class AIPlayer : public AbstractPlayer {
public:
    AIPlayer(Type type);
    ~AIPlayer();
    void performMove(vector<Location> moves, Board* board, GameLogic* logic);
    PlayerType getPType();
private:
    Type type;
    PlayerType pType;
};


#endif //ASSIGNMENT1_AIPLAYER_H
