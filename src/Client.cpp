//
// Created by Rivka Schuss on 05/12/2017.
//
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "../include/Client.h"

using namespace std;

Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP), serverPort(serverPort) {
    clientSocket = 0;
}

Client::~Client() {

}

void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cout << "Error opening socket." << endl;
        return;
    }
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address.";
    }
    struct hostent *server;
    server = gethostbyaddr((const void*) &address, sizeof(address), AF_INET);
    if (server == NULL) {
        throw "Host is unreachable.";
    }
    struct sockaddr_in serverAddress;
    bzero((char*) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;

    memcpy((char*) &serverAddress.sin_addr.s_addr, server->h_addr, server->h_length);

    serverAddress.sin_port  = htons(serverPort);

    if (connect(clientSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        throw "Error connecting to server.";
    }
    cout << "Connected to server." << endl;
}

void Client::sendMove(int row, int col) {
    //char* move =
    cout << "hi" << endl;
}
