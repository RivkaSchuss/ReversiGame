//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_DEFAULTGAMELOGIC_H
#define ASSIGNMENT1_DEFAULTGAMELOGIC_H

#include "AbstractGameLogic.h"
#include "Player.h"
#include <vector>

class DefaultGameLogic : public AbstractGameLogic {

public:
    DefaultGameLogic(Player *secondPlayer);
    ~DefaultGameLogic();
    virtual void playOneTurn(Board* board);
    vector<Location> clearMoveArea(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromUp(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromUpRight(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromRight(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromDownRight(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromDown(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromDownLeft(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromLeft(Cell** table, int size, int rowPos, int colPos, int status);
    Location getFromUpLeft(Cell** table, int size, int rowPos, int colPos, int status);
    int getNotFirstTurn();
private:
    Player* secondPlayer;
    int notFirstTurn;

};


#endif //ASSIGNMENT1_DEFAULTGAMELOGIC_H
