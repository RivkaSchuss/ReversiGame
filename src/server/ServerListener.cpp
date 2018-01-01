//
// Created by Rivka Schuss on 27/12/2017.
//

#include "ServerListener.h"

/**
 * constructor.
 * @param sock the server socket.
 * @param threadList reference to the list of threads.
 * @param manager the commands manager.
 */
ServerListener::ServerListener(int sock, vector<pthread_t> &threadList, CommandsManager* manager) : sock(sock), 
                                                                     threadList(threadList), manager(manager)  {
}

/**
 * struct of arguments for a thread to send.
 */
struct args {
    CommandsManager* cManager;
    int cSock;
};

/**
 * listens for new accepts from a client, and then creates a thread for the accept.
 */
void ServerListener::listeningLoop() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    //endless loop to always receive new client connections.
    while (true) {
        cout << "Waiting for client connections.." << endl;
        int clientSock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (clientSock < 0) {
            cout << "Error accepting client." << endl;
            break;
        }
        cout << "Client connected." << endl;
        //creates the arguments to send for the thread.
        args toSend;
        toSend.cManager = manager;
        toSend.cSock = clientSock;
        //creates a new thread for each accept from the client.
        pthread_t threadHandler;
        threadList.push_back(threadHandler);
        int handleThread = pthread_create(&threadHandler, NULL, sendToHandler, &toSend);
        if (handleThread) {
            cout << "Error: unable to create thread, " << handleThread << endl;
            exit(-1);
        }
    }
}

/**
 *
 * @param info
 * @return
 */
void *ServerListener::sendToHandler(void* info) {
    //casts the arguments to send.
    args *newInfo = (args*) info;
    int sock = newInfo->cSock;
    CommandsManager* manager1 = newInfo->cManager;
    //creates a new handler.
    Handler* handler = new Handler();
    handler->handleClient(manager1, sock);
    delete handler;
}


