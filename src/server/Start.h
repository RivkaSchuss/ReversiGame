//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_START_H
#define REVERSIGAME_START_H


#include "Command.h"
#include "GameID.h"

class Start: public Command {
public:
    Start(int clientSock, vector<GameID> &listOfGames);
    void execute(vector<string> args);
private:
    int clientSock;
    vector<GameID> &listOfGames;
};
#endif //REVERSIGAME_START_H
