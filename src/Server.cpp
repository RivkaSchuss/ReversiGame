//
// Created by Rivka Schuss on 05/12/2017.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "../include/Server.h"

using namespace std;

Server::Server(int portNum) : portNum(portNum) {}

Server::~Server() {}

void Server::start() {
    cout << "hi" << endl;
    int sock;
    bool exit = false;
    struct sockaddr_in sin;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        cout << "Error establishing connection..." << endl;
        return;
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(portNum);

    if (bind(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
        cout << "Error binding the socket." << endl;
        return;
    }
    if (listen(sock, 2) < 0) {
        cout << "Error listening to socket." << endl;
        return;
    }

    struct sockaddr_in client_sin;

    unsigned int addr_len = sizeof(client_sin);

    while(!exit) {
        cout << "Waiting for client connections.." << endl;
        int client_sock = accept(sock, (struct sockaddr*) &client_sin, &addr_len);
        cout << "Client connected." << endl;
        if (client_sock < 0) {
            cout << "Error accepting client." << endl;
            return;
        }
        handleClient(client_sock);

        close(client_sock);
    }
    close(sock);
}

void Server::handleClient(int clientSocket) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = read(clientSocket, buffer, expected_data_len);
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
        return;
    }
    else if (read_bytes < 0) {
        cout << "Error reading." << endl;
        return;
    }
    else {
        cout << buffer;
    }


    int sent_bytes = write(clientSocket, buffer, read_bytes);

    if (sent_bytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
}

int Server::getPortNum() {
    return this->portNum;
}
