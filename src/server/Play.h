//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_PLAY_H
#define REVERSIGAME_PLAY_H


#include "Command.h"

class Play: public Command {
public:
    Play(int clientSock);
    void execute(vector<string> args);
private:
    int clientSock;
};


#endif //REVERSIGAME_PLAY_H
