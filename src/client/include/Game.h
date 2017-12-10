//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_GAME_H
#define ASSIGNMENT1_GAME_H

#include "GameLogic.h"
#include "Player.h"
#include "Client.h"

class Game {
public:
    Game();
    ~Game();
    void runMenu();
    void runGame(Board* board, GameLogic* logic);
    void initConnection();
private:
    Client* client;
};


#endif //ASSIGNMENT1_GAME_H
