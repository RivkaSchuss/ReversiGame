//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_JOIN_H
#define REVERSIGAME_JOIN_H


#include "Command.h"
#include "GameID.h"
#include "GameManager.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class Join: public Command {
public:
    Join(vector<GameID*> &gameList, vector<pthread_t> &threadList);
    static void* sendToGameManager(void* game);
    void execute(vector<string> args);
private:
    vector<GameID*> &gameList;
    vector<pthread_t> &threadList;
};

#endif //REVERSIGAME_JOIN_H
