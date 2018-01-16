//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_JOIN_H
#define REVERSIGAME_JOIN_H


#include "Command.h"
#include "GameID.h"
#include "GameManager.h"
#include "ThreadPool.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

using namespace std;

class Join: public Command {
public:
    Join(vector<GameID*> &gameList, ThreadPool* threadPool);
    static void* sendToGameManager(void* game);
    void execute(vector<string> args);
private:
    vector<GameID*> &gameList;
    ThreadPool* threadPool;
};

#endif //REVERSIGAME_JOIN_H
