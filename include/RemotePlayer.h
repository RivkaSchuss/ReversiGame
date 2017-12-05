//
// Created by Rivka Schuss on 04/12/2017.
//

#ifndef REVERSIGAME_REMOTEPLAYER_H
#define REVERSIGAME_REMOTEPLAYER_H


#include "GameLogic.h"
#include "AbstractPlayer.h"
#include "AIPlayer.h"
#include "Server.h"

class RemotePlayer : public AbstractPlayer {
public:
    RemotePlayer(Type type, Server* server);
    ~RemotePlayer();
    PlayerType getPType();
    void performMove(vector<Location> moves, Board* board, GameLogic* logic);
private:
    Type type;
    PlayerType pType;
    Server* server;
};


#endif //REVERSIGAME_REMOTEPLAYER_H
