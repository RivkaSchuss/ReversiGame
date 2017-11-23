//
// Created by Rivka Schuss on 22/11/2017.
//

#include <iostream>
#include "AIPlayer.h"
using namespace std;

AIPlayer::AIPlayer(Type type) : AbstractPlayer(type), type(type) {

}

AIPlayer::~AIPlayer() {
    delete this;
}


void AIPlayer::performMove(Location* moves, Board* board, GameLogic* logic) {
    cout << "AI player shit" << endl;
}


