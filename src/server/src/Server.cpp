//
// Created by yarin on 06/12/17.
//


#include "../include/Server.h"


#define MAX_NUM_OF_CLIENTS 10
using namespace std;

/**
 * constructor.
 * @param portNum the port number for the connection.
 */
Server::Server(int portNum) : portNum(portNum) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    manager = new CommandsManager(sock, threadList);
    flag = false;
}

/**
 * destructor.
 */
Server::~Server() {}

struct args {
    Server* server;
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
    if (listen(sock, MAX_NUM_OF_CLIENTS) < 0) {
        cout << "Error listening to socket." << endl;
        return;
    }
    //endless loop so that the server is always waiting for new clients to connect
    pthread_t main;
    //setting the arguments for the thread function.
    args threadArgs;
    threadArgs.server = this;
    threadArgs.serverSock = sock;
    threadArgs.commandsManager = manager;
    //creating the main thread for the server.
    int mainThread = pthread_create(&main, NULL, handleClient, &threadArgs);
    threadList.push_back(main);
    if (mainThread) {
        cout << "Error: unable to create thread, " << mainThread << endl;
        exit(-1);
    }
    //receiving "exit" through the server, and closing all processes.
    string exitCommand;
    cin >> exitCommand;
    if (strcmp(exitCommand.c_str(), "exit") == 0) {
        closeProcesses();
        flag = true;
        delete manager;
    }
    while(strcmp(exitCommand.c_str(), "exit") != 0) {
        if (strcmp(exitCommand.c_str(), "exit") == 0) {
            closeProcesses();
            delete manager;
            flag = true;
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "If you want to exit, please enter: exit" << endl;
            cin >> exitCommand;
        }
    }
}

/**
 * handles the client.
 * @param threadArgs the arguments to send.
 * @return nothing.
 */
void* Server::handleClient(void* threadArgs) {
    //casting the arguments received through the thread.
    args *newInfo = (args*) threadArgs;
    vector<pthread_t> &threadList = newInfo->server->threadList;
    int sock = newInfo->serverSock;
    CommandsManager* manager = newInfo->commandsManager;
    //creating a server listener.
    ServerListener* listener = new ServerListener(sock, threadList, manager);
    listener->listeningLoop();
    delete listener;
    return NULL;
}

/**
 * cancels the threads and closes all the sockets.
 */
void Server::closeProcesses() {
    //canceling all the threads in the list of threads.
    for (int i = 0; i < threadList.size(); i++) {
        pthread_cancel(threadList[i]);
        pthread_join(threadList[i], NULL);
    }
    //calling the function to close all of the sockets.
    manager->closeSockets();
    close(sock);
    threadList.clear();
}

bool Server::getFlag() {
    return this->flag;
}


