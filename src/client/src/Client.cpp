//
// Created by Rivka Schuss on 05/12/2017.
//

#include "../include/Client.h"


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
    char turn[4096];
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
    string command, name, send;
    char buffer[4096];
    char yet[4096] = "yet";
    int bytes_received;
    while (strcmp(turn, "1") != 0 && strcmp(turn, "2") != 0) {
        cout << "Please enter your command:" << endl;
        cin >> command;
        if (strcmp(command.c_str(), "list_games") != 0) {
            cin >> name;
            send = command + ' ' + name;
        } else {
            send = command;
        }
        strcpy(buffer, send.c_str());
        int command_toSend = write(clientSocket, buffer, sizeof(buffer));
        if (command_toSend < 0) {
            cout << "Error writing to the server." << endl;
            exit(-1);
        }
        //reading from the server
        bytes_received = read(clientSocket, turn, sizeof(turn));
        if (bytes_received < 0) {
            cout << "Error reading from server." << endl;
            exit(-1);
        }
        int turnInt;
        sscanf(turn, "%d", &turnInt);
        string stringToSend;
        switch(turnInt) {
            case 1:
                cout << "Waiting for the other player to join..." << endl;
                //reading
                bytes_received = read(clientSocket, turn, sizeof(turn));
                if (bytes_received < 0) {
                    cout << "Error reading from server." << endl;
                    exit(-1);
                }
                if (strcmp(turn, "2") == 0) {
                    type = first;
                    available = true;
                }
                break;
            case 2:
                type = second;
                available = false;
                break;
            case -1:
                stringToSend = "That name is already taken.";
                sendErrors(stringToSend);
                break;
            case -2:
                stringToSend = "That game is full.";
                sendErrors(stringToSend);
                break;
            case -3:
                stringToSend = "That game doesn't exist.";
                sendErrors(stringToSend);
                break;
            default:
                cout << turn << endl;
                int command_toSend = write(clientSocket, yet, sizeof(yet));
                if (command_toSend < 0) {
                    cout << "Error writing to the server." << endl;
                    exit(-1);
                }
                break;
        }
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

void Client::sendErrors(string stringToPrint) {
    char flag[4096] = "flag";
    cout << stringToPrint << endl;
    int command_toSend = write(clientSocket, flag, sizeof(flag));
    if (command_toSend < 0) {
        cout << "Error writing to the server." << endl;
        exit(-1);
    }
}
