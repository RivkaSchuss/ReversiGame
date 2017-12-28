//
// Created by Rivka Schuss on 25/12/2017.
//

#include "CommandsManager.h"
#include "Join.h"
#include "Start.h"
#include "ListGames.h"


CommandsManager::CommandsManager(int sock, vector<pthread_t> &threadList) : sock(sock) , threadList(threadList) {
    commandsMap["join"] = new Join(gameList, threadList);
    commandsMap["start"] = new Start(gameList);
    commandsMap["list_games"] = new ListGames(gameList);
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

int CommandsManager::getSock() {
    return this->sock;
}

void CommandsManager::closeSockets() {
    for (int i = 0; i < gameList.size(); i++) {
        close(gameList[i]->getFirstSock());
        close(gameList[i]->getSecondSock());
    }
}
