//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_CLOSE_H
#define REVERSIGAME_CLOSE_H

#include "Command.h"
#include "GameID.h"

class Close: public Command {
public:
    Close(int clientSock, vector<GameID> &gameList);
    void execute(vector<string> args);
private:
    int clientSock;
    vector<GameID> &gameList;
};


#endif //REVERSIGAME_CLOSE_H
