//
// Created by yarin on 06/12/17.
//

#ifndef REVERSIGAME_SERVER_H
#define REVERSIGAME_SERVER_H

#include <pthread.h>
#include <vector>
#include "GameID.h"
#include "GameManager.h"
#include "CommandsManager.h"
#include "ServerListener.h"

using namespace std;

class Server {
public:
    Server(int portNum);
    ~Server();
    void start();
    void close();
    static void* handleClient(void* threadArgs);
private:
    CommandsManager* manager;
    vector<pthread_t> threadList;
    int portNum;
    int sock;
};


#endif //REVERSIGAME_SERVER_H