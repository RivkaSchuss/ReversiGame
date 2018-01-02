//
// Created by Rivka Schuss on 05/12/2017.
//

#ifndef REVERSIGAME_CLIENT_H
#define REVERSIGAME_CLIENT_H

#include <iostream>
#include <limits>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

using namespace std;

enum ClientType {first, second};

class Client {
public:
    Client(const char *serverIP, int serverPort);
    ~Client();
    void connectToServer();
    void sendErrors(string stringToPrint);
    ClientType getType();
    bool getAvailable();
    void updateTurn(bool update);
    int getSocket();
private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
    ClientType type;
    bool available;
};


#endif //REVERSIGAME_CLIENT_H
