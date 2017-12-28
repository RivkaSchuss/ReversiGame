//
// Created by Rivka Schuss on 27/12/2017.
//

#ifndef REVERSIGAME_SERVERLISTENER_H
#define REVERSIGAME_SERVERLISTENER_H


#include "CommandsManager.h"

class ServerListener {
public:
    ServerListener(int sock, vector<pthread_t> &threadList, CommandsManager* manager);
    void listeningLoop();
    static void *sendToHandler(void *manager);
private:
    vector<pthread_t> &threadList;
    CommandsManager* manager;
    int sock;
};


#endif //REVERSIGAME_SERVERLISTENER_H
