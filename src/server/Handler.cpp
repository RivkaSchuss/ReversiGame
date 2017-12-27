//
// Created by Rivka Schuss on 27/12/2017.
//

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Handler.h"
#include "CommandsManager.h"

using namespace std;

void Handler::handleClient(CommandsManager* manager, int clientSock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = read(clientSock, buffer, expected_data_len);
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
    }
    vector<string> commands;
    string input(buffer);
    size_t spaceIndex = input.find(" ");
    string command = input.substr(0, spaceIndex);
    string name = input.substr(spaceIndex + 1, input.length() - 1);
    vector<string> args;
    args.push_back(name);
    string sSock = to_string(clientSock);
    args.push_back(sSock);
    manager->executeCommand(command, args);
}

