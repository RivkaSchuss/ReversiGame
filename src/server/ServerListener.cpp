//
// Created by Rivka Schuss on 27/12/2017.
//

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <pthread.h>
#include "ServerListener.h"
#include "Handler.h"
#include "ThreadList.h"

using namespace std;

ServerListener::ServerListener(int sock) : sock(sock) {
    manager = new CommandsManager(sock);
}

struct args {
    CommandsManager* cManager;
    int cSock;
};

void ServerListener::listeningLoop() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    while (true) {
        cout << "Waiting for client connections.." << endl;
        int clientSock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (clientSock < 0) {
            cout << "Error accepting client." << endl;
            break;
        }
        cout << "Client connected." << endl;
        args toSend;
        toSend.cManager = manager;
        toSend.cSock = clientSock;
        pthread_t threadHandler;
        int handleThread = pthread_create(&threadHandler, NULL, sendToHandler, &toSend);
        if (handleThread) {
            cout << "Error: unable to create thread, " << handleThread << endl;
            exit(-1);
        }
    }
}

void *ServerListener::sendToHandler(void* info) {
    args *newInfo = (args*) info;
    int sock = newInfo->cSock;
    CommandsManager* manager1 = newInfo->cManager;
    Handler* handler = new Handler();
    handler->handleClient(manager1, sock);
    delete handler;
}


