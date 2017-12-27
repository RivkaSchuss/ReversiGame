//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_START_H
#define REVERSIGAME_START_H


#include "Command.h"
#include "GameID.h"

class Start: public Command {
public:
    Start(vector<GameID*> &gameList);
    void execute(vector<string> args);
private:
    vector<GameID*> &gameList;
};
#endif //REVERSIGAME_START_H
