//
// Created by Rivka Schuss on 27/12/2017.
//

#ifndef REVERSIGAME_HANDLER_H
#define REVERSIGAME_HANDLER_H


#include "CommandsManager.h"

class Handler {
public:
    void handleClient(CommandsManager* manager, int clientSock);
};


#endif //REVERSIGAME_HANDLER_H
