//
// Created by Rivka Schuss on 25/12/2017.
//

#include "CommandsManager.h"
#include "Join.h"
#include "Start.h"
#include "ListGames.h"

/**
 * constructor that builds the map of commands.
 * @param sock the server socket.
 * @param threadList a reference to the list of threads.
 */
CommandsManager::CommandsManager(int sock, vector<pthread_t> &threadList) : sock(sock) , threadList(threadList) {
    commandsMap["join"] = new Join(gameList, threadList);
    commandsMap["start"] = new Start(gameList);
    commandsMap["list_games"] = new ListGames(gameList);
}

/**
 * destructor- iterates over the map and deletes the commands.
 */
CommandsManager::~CommandsManager() {
    map<string, Command*>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}

/**
 * executes a command based on the string received
 * @param command the command to execute.
 * @param args the list of args for the command.
 */
void CommandsManager::executeCommand(string command, vector<string> args) {
    Command* commandObj = commandsMap[command];
    commandObj->execute(args);
}

/**
 * closes all of the sockets within the game list.
 */
void CommandsManager::closeSockets() {
    for (int i = 0; i < gameList.size(); i++) {
        close(gameList[i]->getFirstSock());
        close(gameList[i]->getSecondSock());
        delete gameList[i];
    }
    gameList.clear();
}
