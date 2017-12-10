//
// Created by Rivka Schuss on 04/12/2017.
//

#ifndef REVERSIGAME_REMOTEPLAYER_H
#define REVERSIGAME_REMOTEPLAYER_H


#include "GameLogic.h"
#include "AbstractPlayer.h"
#include "AIPlayer.h"

class RemotePlayer : public AbstractPlayer {
public:
    RemotePlayer(Type type);
    ~RemotePlayer();
    PlayerType getPType();
    void performMove(vector<Location> moves, Board* board, GameLogic* logic);
private:
    Type type;
    PlayerType pType;
};


#endif //REVERSIGAME_REMOTEPLAYER_H
