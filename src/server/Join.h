//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_JOIN_H
#define REVERSIGAME_JOIN_H


#include "Command.h"
#include "GameID.h"

class Join: public Command {
public:
    Join(vector<GameID*> &gameList);
    void execute(vector<string> args);
private:
    vector<GameID*> &gameList;
};

#endif //REVERSIGAME_JOIN_H
