//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Close.h"
#include "GameID.h"
#include <iostream>

using namespace std;


Close::Close(int clientSock, vector<GameID> &gameList) : clientSock(clientSock), gameList(gameList) {

}

void Close::execute(vector<string> args) {

}
