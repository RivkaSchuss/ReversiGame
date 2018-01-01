//
// Created by Rivka Schuss on 26/12/2017.
//

#ifndef REVERSIGAME_GAMEMANAGER_H
#define REVERSIGAME_GAMEMANAGER_H

#include <iostream>
#include <string.h>
#include <string>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include "GameID.h"

using namespace std;

class GameManager {
public:
    GameManager(GameID* game);
    void startGame();
    void handlePlayer(int playerSock);
    void setExit(bool change);
    void manage(int playerSock, int otherSock);
    ~GameManager();
private:
    GameID* game;
    int sock1;
    int sock2;
    bool exit;
};


#endif //REVERSIGAME_GAMEMANAGER_H
