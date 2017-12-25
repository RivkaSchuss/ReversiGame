//
// Created by yarin on 06/12/17.
//

#ifndef REVERSIGAME_SERVER_H
#define REVERSIGAME_SERVER_H

#include <pthread.h>
#include <vector>
#include "GameID.h"

using namespace std;

class Server {
public:
    Server(int portNum);
    ~Server();
    void start();
    void handleClient(int clientSocket);
    vector<GameID> *getGameList();
private:
    vector<GameID> *gameList;
    int portNum;
    int client_sock1;
    int client_sock2;
    bool exit;

};


#endif //REVERSIGAME_SERVER_H