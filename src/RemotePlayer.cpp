//
// Created by Rivka Schuss on 04/12/2017.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "../include/RemotePlayer.h"

using namespace std;

RemotePlayer::RemotePlayer(Type type) : AbstractPlayer(type), type(type) {
    pType = Remote;
}

RemotePlayer::~RemotePlayer() {

}

PlayerType RemotePlayer::getPType() {
    return pType;
}


void RemotePlayer::performMove(vector<Location> moves, Board* board, GameLogic* logic) {
    cout << "O: It's your move." << endl;
}

