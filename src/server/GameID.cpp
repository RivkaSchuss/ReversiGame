//
// Created by Rivka Schuss on 25/12/2017.
//

#include "GameID.h"

/**
 * constructor
 * @param name name of the current game
 */
GameID::GameID(string name) : name(name) {
    status = noPlayers;
}

/**
 * destructor
 */
GameID::~GameID() {}

/**
 * updates the availability to the game.
 * @param status the new availability.
 */
void GameID::updateAvailability(Available status) {
    this->status = status;
}

/**
 * returns the name of the game.
 * @return the game name.
 */
string GameID::getName() {
    return this->name;
}

/**
 * sets the client of the first client.
 * @param firstSock the socket to update.
 */
void GameID::setFirstSock(int firstSock) {
    this->player1Sock = firstSock;
}

/**
 * sets the client of the second client.
 * @param secSock the socket to update.
 */
void GameID::setSecondSock(int secSock) {
    this->player2Sock = secSock;
}

/**
 * returns the availability.
 * @return the availability,
 */
Available GameID::getAvailability() {
    return this->status;
}

/**
 * returns the first client's socket.
 * @return the first client's socket.
 */
int GameID::getFirstSock() {
    return this->player1Sock;
}

/**
 * returns the second client's socket.
 * @return the second client's socket.
 */
int GameID::getSecondSock() {
    return this->player2Sock;
}

