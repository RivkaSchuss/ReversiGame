//
// Created by yarin on 06/12/17.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "Server.h"
#include "GameID.h"

using namespace std;

/**
 * constructor.
 * @param portNum the port number for the connection.
 */
Server::Server(int portNum) : portNum(portNum) {
    exit = false;
    gameList = new vector<GameID>;
}

/**
 * destructor.
 */
Server::~Server() {}

/**
 * starts the server.
 */
void Server::start() {
    int sock;
    struct sockaddr_in sin;
    //creating the socket.
    sock = socket(AF_INET, SOCK_STREAM, 0);
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
    struct sockaddr_in client1_sin;
    struct sockaddr_in client2_sin;
    unsigned int addr_len1 = sizeof(client1_sin);
    unsigned int addr_len2 = sizeof(client2_sin);
    char first[2] = "1";
    char second[2] = "2";
    //endless loop so that the server is always waiting for new clients to connect
    while (true) {
        cout << "Waiting for client connections.." << endl;
        //accepting the first client
        client_sock1 = accept(sock, (struct sockaddr *) &client1_sin, &addr_len1);
        if (client_sock1 < 0) {
            cout << "Error accepting client." << endl;
            return;
        }
        cout << "Client 1 connected." << endl;
        //writing to the first client that he is the first player
        int sent_bytes1 = write(client_sock1, first, sizeof(first));
        if (sent_bytes1 < 0) {
            cout << "Error sending to client." << endl;
            return;
        }
        //accepting the second player
        client_sock2 = accept(sock, (struct sockaddr *) &client2_sin, &addr_len2);
        if (client_sock2 < 0) {
            cout << "Error accepting client." << endl;
            return;
        }
        //writing to the first client
        sent_bytes1 = write(client_sock1, first, sizeof(first));
        if (sent_bytes1 < 0) {
            cout << "Error sending to client." << endl;
            return;
        }
        //writing to the second client that hes the second player
        int sent_bytes2 = write(client_sock2, second, sizeof(second));
        if (sent_bytes2 < 0) {
            cout << "Error sending to client." << endl;
            return;
        }
        cout << "Client 2 connected." << endl;
        //handling the clients.
        while (!exit) {
            handleClient(client_sock1);
            handleClient(client_sock2);
        }
        //closing the client sockets.
        close(client_sock1);
        close(client_sock2);
        exit = false;
    }
    //stop();
}

void Server::handleClient(int clientSocket) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    //if we are the first client
    if (clientSocket == client_sock1) {
        //reading
        int read_bytes = read(clientSocket, buffer, expected_data_len);
        //if the connection has been closed
        if (read_bytes == 0) {
            cout << "Connection is closed." << endl;
            exit = true;
            return;
            //if the read has returned the string "end", the game ends
        } else if (strcmp(buffer, "End") == 0) {
            handleClient(client_sock2);
            exit = true;
            return;
        } else if (read_bytes < 0) {
            cout << "Error reading." << endl;
            return;
        } else {
            //if the read has returned the string "nomove", there are no more moves
            if (strcmp(buffer, "NoMove") == 0) {
                char noChange[4096] = "X played: 0, 0";
                //writing
                int sent_bytes = write(client_sock2, noChange, read_bytes);
                if (sent_bytes < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                return;
            }
            //writing to the client dependent on what was read.
            int sent_bytes = write(client_sock2, buffer, read_bytes);
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
        }
        //if we are the second client
    } else {
        int read_bytes = read(clientSocket, buffer, expected_data_len);
        if (read_bytes == 0) {
            cout << "Connection is closed." << endl;
            exit = true;
            return;
        } else if (strcmp(buffer, "End") == 0) {
            handleClient(client_sock1);
            exit = true;
            return;
        } else if (read_bytes < 0) {
            cout << "Error reading." << endl;
            return;
        } else {
            if (strcmp(buffer, "NoMove") == 0) {
                char noChange[4096] = "O played: 0, 0";
                int sent_bytes = write(client_sock1, noChange, read_bytes);
                if (sent_bytes < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                return;
            }
            int sent_bytes = write(client_sock1, buffer, read_bytes);
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
        }
    }
}

vector<GameID> *Server::getGameList() {
    return this->gameList;
}
