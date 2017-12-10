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

/**
 * constructor.
 * @param serverIP the server ip address.
 * @param serverPort the server port number.
 */
Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP),
                                                       serverPort(serverPort) {
    clientSocket = 0;
}

/**
 * destructor.
 */
Client::~Client() {

}

/**
 * connects the client to the server.
 */
void Client::connectToServer() {
    char turn[2];
    //creating a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    //checking if the socket is valid
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
    //connecting the client to the server
    if (connect(clientSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        throw "Error connecting to server.";
    }
    cout << "Connected to server." << endl;
    //reading from the server
    int bytes_received = read(clientSocket, turn, sizeof(turn));
    if (bytes_received < 0) {
        cout << "Error reading from server." << endl;
    }
    //assigning the client type according to the number we've read from the server.
    if (strcmp(turn, "1") == 0) {
        cout << "Waiting for the other player to join..." << endl;
        //reading
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

/**
 * gets the type of the client.
 * @return an enum, first or second.
 */
ClientType Client::getType() {
    return this->type;
}

/**
 * returns if the client is available or not.
 * @return boolean true or false.
 */
bool Client::getAvailable() {
    return this->available;
}

/**
 * updates the turn of the client.
 * @param update the boolean to update.
 */
void Client::updateTurn(bool update) {
    this->available = update;
}

/**
 * returns the socket.
 * @return the client socket.
 */
int Client::getSocket() {
    return this->clientSocket;
}
