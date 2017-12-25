//
// Created by Rivka Schuss on 25/12/2017.
//

#include "GameID.h"

GameID::GameID(string name) : name(name) {

}


GameID::~GameID() {

}

void GameID::updateAvailability(Available status) {
    this->status = status;
}

string GameID::getName() {
    return this->name;
}

void GameID::setFirstSock(int firstSock) {
    this->player1Sock = firstSock;
}

void GameID::setSecondSock(int secSock) {
    this->player2Sock = secSock;
}

Available GameID::getAvailability() {
    return this->status;
}

