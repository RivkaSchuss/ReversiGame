//
// Created by yarin on 06/12/17.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <cstdlib>

#include "Server.h"
#include "GameID.h"
#include "ThreadList.h"

using namespace std;

/**
 * constructor.
 * @param portNum the port number for the connection.
 */
Server::Server(int portNum) : portNum(portNum) {
    exit = false;
    gameManager = new GameManager();
    sock = socket(AF_INET, SOCK_STREAM, 0);
}

/**
 * destructor.
 */
Server::~Server() {}

/**
 * starts the server.
 */
void Server::start() {
    struct sockaddr_in sin;
    if (sock < 0) {
        cout << "Error establishing connection..." << endl;
        return;
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(portNum);
    //binding the socket
    if (bind(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
        cout << "Error binding the socket." << endl;
        return;
    }
    //listening
    if (listen(sock, 2) < 0) {
        cout << "Error listening to socket." << endl;
        return;
    }
    //endless loop so that the server is always waiting for new clients to connect
    pthread_t main;
    //sleep(5);
    int mainThread = pthread_create(&main, NULL, handleClient, (void*) sock);
    if (mainThread) {
        cout << "Error: unable to create thread, " << mainThread << endl;
    }
    pthread_exit(NULL);
    //ThreadList::getInstance()->add(mainThread);
}

void* Server::handleClient(void* sock) {
    ServerListener* listener = new ServerListener((long) sock);
    listener->listeningLoop();
    delete listener;
}


