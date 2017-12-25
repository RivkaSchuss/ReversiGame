//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Play.h"
#include <iostream>

using namespace std;


Play::Play(int clientSock) : clientSock(clientSock) {

}

void Play::execute(vector<string> args) {
    int xMove, yMove;
    sscanf(args[0].c_str(), "%d", &xMove);
    sscanf(args[1].c_str(), "%d", &yMove);


}


