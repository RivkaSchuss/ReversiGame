//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_COMMANDSMANAGER_H
#define REVERSIGAME_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
#include "GameID.h"

class CommandsManager {
public:
    CommandsManager(int sock);
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
    int getSock();
private:
    map<string, Command*> commandsMap;
    vector<GameID*> gameList;
    int sock;
};


#endif //REVERSIGAME_COMMANDSMANAGER_H
