//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_START_H
#define REVERSIGAME_START_H


#include "Command.h"
#include "GameID.h"

class Start: public Command {
public:
    Start(int clientSock);
    void execute(vector<string> args);
private:
    int clientSock;
};
#endif //REVERSIGAME_START_H
