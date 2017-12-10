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

/**
 * constructor.
 * @param type the type of player.
 */
RemotePlayer::RemotePlayer(Type type) : AbstractPlayer(type), type(type) {
    pType = Remote;
}

/**
 * destructor.
 */
RemotePlayer::~RemotePlayer() {

}

/**
 * gets the type of the player.
 * @return the player type.
 */
PlayerType RemotePlayer::getPType() {
    return pType;
}

/**
 * performs a move.
 * @param moves the list of possible moves.
 * @param board the game board.
 * @param logic the game logic.
 */
void RemotePlayer::performMove(vector<Location> moves, Board* board, GameLogic* logic) {
    cout << "O: It's your move." << endl;
}

