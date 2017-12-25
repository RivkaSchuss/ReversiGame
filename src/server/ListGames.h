//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_LIST_H
#define REVERSIGAME_LIST_H


#include "Command.h"
#include "Server.h"
#include "GameID.h"

class ListGames: public Command {
public:
    ListGames(int clientSock, vector<GameID> &gameList);
    void execute(vector<string> args);
private:
    int clientSock;
    vector<GameID> &gameList;
};


#endif //REVERSIGAME_LIST_H
