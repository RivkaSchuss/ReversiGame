//
// Created by Rivka Schuss on 25/12/2017.
//

#include "CommandsManager.h"
#include "Join.h"
#include "Start.h"
#include "Close.h"
#include "ListGames.h"


CommandsManager::CommandsManager(int sock) : sock(sock) {
    commandsMap["join"] = new Join(gameList);
    commandsMap["start"] = new Start(gameList);
    commandsMap["close"] = new Close(gameList);
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
    cout << gameList[0]->getAvailability() << endl;
}

int CommandsManager::getSock() {
    return this->sock;
}
