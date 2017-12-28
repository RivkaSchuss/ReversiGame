//
// Created by yarin on 06/12/17.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Server.h"


#define MAX_NUM_OF_GAMES 10
using namespace std;

/**
 * constructor.
 * @param portNum the port number for the connection.
 */
Server::Server(int portNum) : portNum(portNum) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    manager = new CommandsManager(sock, threadList);
}

/**
 * destructor.
 */
Server::~Server() {}

struct args {
    vector<pthread_t> threadsList;
    int serverSock;
    CommandsManager* commandsManager;
};

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
    if (listen(sock, MAX_NUM_OF_GAMES) < 0) {
        cout << "Error listening to socket." << endl;
        return;
    }
    //endless loop so that the server is always waiting for new clients to connect
    pthread_t main;
    args threadArgs;
    threadArgs.threadsList = threadList;
    threadArgs.serverSock = sock;
    threadArgs.commandsManager = manager;
    int mainThread = pthread_create(&main, NULL, handleClient, &threadArgs);
    if (mainThread) {
        cout << "Error: unable to create thread, " << mainThread << endl;
        exit(-1);
    }
    threadList.push_back(main);
    string exitCommand;
    cin >> exitCommand;
    if (strcmp(exitCommand.c_str(), "exit") == 0) {
        close();
    }
    //pthread_exit(NULL);
}

void* Server::handleClient(void* threadArgs) {
    args *newInfo = (args*) threadArgs;
    vector<pthread_t> &threadList = newInfo->threadsList;
    int sock = newInfo->serverSock;
    CommandsManager* manager = newInfo->commandsManager;
    ServerListener* listener = new ServerListener(sock, threadList, manager);
    listener->listeningLoop();
    delete listener;
}

void Server::close() {
    pthread_cancel(threadList[0]);
    for (int i = 1; i < threadList.size() - 1; i++) {
        pthread_cancel(threadList[i]);
    }
    manager->closeSockets();
}


