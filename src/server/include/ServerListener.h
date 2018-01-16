//
// Created by Rivka Schuss on 27/12/2017.
//

#ifndef REVERSIGAME_SERVERLISTENER_H
#define REVERSIGAME_SERVERLISTENER_H

#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <netinet/in.h>
#include <pthread.h>
#include "Handler.h"
#include "CommandsManager.h"

using namespace std;

class ServerListener {
public:
    ServerListener(int sock, ThreadPool* threadPool, CommandsManager* manager);
    void listeningLoop();
    static void *sendToHandler(void *manager);
private:
    ThreadPool* threadPool;
    CommandsManager* manager;
    int sock;
};


#endif //REVERSIGAME_SERVERLISTENER_H
