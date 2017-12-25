//
// Created by Rivka Schuss on 25/12/2017.
//

#include "CommandsManager.h"
#include "Join.h"
#include "Start.h"
#include "Close.h"
#include "Play.h"
#include "ListGames.h"


CommandsManager::CommandsManager(int clientSock, vector<GameID> &gameList) : clientSock(clientSock),
                                                                             gameList(gameList) {
    commandsMap["join"] = new Join(clientSock, gameList);
    commandsMap["start"] = new Start(clientSock, gameList);
    commandsMap["close"] = new Close(clientSock, gameList);
    commandsMap["play"] = new Play(clientSock);
    commandsMap["list"] = new ListGames(clientSock, gameList);
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
