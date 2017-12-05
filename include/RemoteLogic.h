//
// Created by Rivka Schuss on 05/12/2017.
//

#ifndef REVERSIGAME_REMOTELOGIC_H
#define REVERSIGAME_REMOTELOGIC_H


#include "AbstractGameLogic.h"
#include "DefaultGameLogic.h"

class RemoteLogic : public DefaultGameLogic {
public:
    RemoteLogic(Player *secondPlayer);
    ~RemoteLogic();
    void playOneTurn(Board* board);
private:
    Player* secondPlayer;
    int notFirstTurn;
};


#endif //REVERSIGAME_REMOTELOGIC_H
