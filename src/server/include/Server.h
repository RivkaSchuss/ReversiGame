//
// Created by yarin on 06/12/17.
//

#ifndef REVERSIGAME_SERVER_H
#define REVERSIGAME_SERVER_H

#include <pthread.h>
#include <iostream>
#include <limits>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <string.h>
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
    void closeProcesses();
    static void* handleClient(void* threadArgs);
    bool getFlag();
private:
    CommandsManager* manager;
    vector<pthread_t> threadList;
    int portNum;
    int sock;
    bool flag;
};


#endif //REVERSIGAME_SERVER_H