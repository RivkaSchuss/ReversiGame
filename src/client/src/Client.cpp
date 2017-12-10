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

Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP),
                                                       serverPort(serverPort) {
    clientSocket = 0;
}

Client::~Client() {

}

void Client::connectToServer() {
    char turn[2];
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
    int bytes_received = read(clientSocket, turn, sizeof(turn));
    if (bytes_received < 0) {
        cout << "Error reading from server." << endl;
    }
    if (strcmp(turn, "1") == 0) {
        cout << "Waiting for the other player to join..." << endl;
        bytes_received = read(clientSocket, turn, sizeof(turn));
        if (bytes_received < 0) {
            cout << "Error reading from server." << endl;
        }
        type = first;
        available = true;
    } else if (strcmp(turn, "2") == 0){
        type = second;
        available = false;
    }
}

ClientType Client::getType() {
    return this->type;
}

bool Client::getAvailable() {
    return this->available;
}

void Client::updateTurn(bool update) {
    this->available = update;
}

int Client::getSocket() {
    return this->clientSocket;
}
