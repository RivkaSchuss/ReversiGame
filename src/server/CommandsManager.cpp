//
// Created by Rivka Schuss on 25/12/2017.
//

#include "CommandsManager.h"
#include "Join.h"
#include "Start.h"
#include "Close.h"
#include "ListGames.h"


CommandsManager::CommandsManager(int clientSock, vector<GameID> &gameList) : clientSock(clientSock),
                                                                             gameList(gameList) {
    commandsMap["join"] = new Join(clientSock);
    commandsMap["start"] = new Start(clientSock);
    commandsMap["close"] = new Close(clientSock);
    commandsMap["list_games"] = new ListGames(clientSock);
}

CommandsManager::~CommandsManager() {
    map<string, Command*>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}

void CommandsManager::executeCommand(string command, vector<string> args) {
    Command* commandObj = commandsMap[command];
    commandObj->execute(args);
}
