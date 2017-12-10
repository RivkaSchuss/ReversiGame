//
// Created by yarin on 03/11/17.
//

#ifndef ASSIGNMENT1_ABSTRACTPLAYER_H
#define ASSIGNMENT1_ABSTRACTPLAYER_H

#include "Location.h"
#include "Player.h"
#include <vector>

using namespace std;

class AbstractPlayer : public Player {
public:
    AbstractPlayer(Type type);
    ~AbstractPlayer();
    virtual void performMove(vector<Location> moves, Board* board, GameLogic* logic) = 0;
    //virtual Server* getServer();
    virtual PlayerType getPType() = 0;
protected:
    Type type;
private:
    //the members of the class
    PlayerType pType;
};


#endif //ASSIGNMENT1_ABSTRACTPLAYER_H
