//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_COMMAND_H
#define REVERSIGAME_COMMAND_H


#include <iostream>
#include <vector>

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};
#endif //REVERSIGAME_COMMAND_H
