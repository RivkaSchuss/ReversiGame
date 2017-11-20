//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_GAME_H
#define ASSIGNMENT1_GAME_H

#include "GameLogic.h"
#include "Player.h"

class Game {

public:
    Game(Player* blackPlayer, Player* whitePlayer, Board* board, GameLogic* logic);
    ~Game();
    void run();

private:
    //members of the class:
    GameLogic* logic;
    Board* board;
    Player* blackPlayer;
    Player* whitePlayer;

};


#endif //ASSIGNMENT1_GAME_H
