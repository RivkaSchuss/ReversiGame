//
// Created by Rivka Schuss on 27/12/2017.
//

#ifndef REVERSIGAME_HANDLER_H
#define REVERSIGAME_HANDLER_H


#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "CommandsManager.h"
#include "GameManager.h"

using namespace std;

class Handler {
public:
    void handleClient(CommandsManager* manager, int clientSock);
    string intToString(int num);
};


#endif //REVERSIGAME_HANDLER_H
