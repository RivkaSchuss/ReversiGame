//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_COMMANDSMANAGER_H
#define REVERSIGAME_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
#include "GameID.h"
#include "ThreadPool.h"

class CommandsManager {
public:
    CommandsManager(int sock, ThreadPool* threadPool);
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
    void closeSockets();
private:
    map<string, Command*> commandsMap;
    vector<GameID*> gameList;
    ThreadPool* threadPool;
    int sock;
};


#endif //REVERSIGAME_COMMANDSMANAGER_H
