//
// Created by Rivka Schuss on 26/12/2017.
//

#include "../include/GameManager.h"

/**
 * constructor.
 * @param game the game to manage.
 */
GameManager::GameManager(GameID* game) : game(game){
    sock1 = game->getFirstSock();
    sock2 = game->getSecondSock();
    exit = false;
}

/**
 * destructor.
 */
GameManager::~GameManager() {}

/**
 * start the game with a loop.
 */
void GameManager::startGame() {
    while(!exit) {
        handlePlayer(sock1);
        handlePlayer(sock2);
    }
}

/**
 * handles the player based on the socket received.
 * @param playerSock
 */
void GameManager::handlePlayer(int playerSock) {
    //if we are the first client
    if (playerSock == sock1) {
        manage(playerSock, sock2);
    } else {
        manage(playerSock, sock1);
    }
}

/**
 * manages the player, reads from the client and writes to the client when there are no moves,
 * or when the game needs to end.
 * @param playerSock the current player's socket.
 * @param otherSock the other player's socket.
 */
void GameManager::manage(int playerSock, int otherSock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    //reads the message from the client.
    int read_bytes = read(playerSock, buffer, expected_data_len);
    //if the connection has been closed
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
        exit = true;
        return;
        //if the read has returned the string "end", the game ends
    } else if (strcmp(buffer, "End") == 0) {
        handlePlayer(otherSock);
        exit = true;
        return;
    } else if (read_bytes < 0) {
        //cout << "Error reading." << endl;
        return;
    } else {
        //if the read has returned the string "NoMove", there are no more moves
        if (strcmp(buffer, "NoMove") == 0) {
            char noChange[4096] = "There are no more moves!";
            //writing
            int sent_bytes = write(otherSock, noChange, read_bytes);
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
            return;
        }
        //writing to the client dependent on what was read.
        int sent_bytes = write(otherSock, buffer, read_bytes);
        if (sent_bytes < 0) {
            cout << "Error sending to client." << endl;
            return;
        }
    }
}

