//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_START_H
#define REVERSIGAME_START_H

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "Command.h"
#include "GameID.h"

using namespace std;

class Start: public Command {
public:
    Start(vector<GameID*> &gameList);
    void execute(vector<string> args);
private:
    vector<GameID*> &gameList;
};
#endif //REVERSIGAME_START_H
