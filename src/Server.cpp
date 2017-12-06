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
    struct sockaddr_in client1_sin;
    struct sockaddr_in client2_sin;
    unsigned int addr_len1 = sizeof(client1_sin);
    unsigned int addr_len2 = sizeof(client2_sin);
    char buffer[4096] = "Connected to server. \n Waiting for other player to join...";
    cout << "Waiting for client connections.." << endl;
    client_sock1 = accept(sock, (struct sockaddr*) &client1_sin, &addr_len1);
    if (client_sock1 < 0) {
        cout << "Error accepting client." << endl;
        return;
    }
    int sent_bytes = write(client_sock1, buffer, sizeof(buffer));
    if (sent_bytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
    client_sock2 = accept(sock, (struct sockaddr*) &client2_sin, &addr_len2);
    if (client_sock2 < 0) {
        cout << "Error accepting client." << endl;
        return;
    }
    cout << "Client2 connected." << endl;
    handleClient(client_sock1);
    handleClient(client_sock2);
    //close(client_sock1);
    //close(client_sock2);
    //stop();
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
        int sent_bytes = write(clientSocket, buffer, read_bytes);
        if (sent_bytes < 0) {
            cout << "Error sending to client." << endl;
            return;
        }
    }
}

int Server::getPortNum() {
    return this->portNum;
}

void Server::stop() {
    close(sock);
}

int Server::getClientSock1() {
    return this->client_sock1;
}

int Server::getClientSock2() {
    return this->client_sock2;
}
