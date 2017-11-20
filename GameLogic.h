//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_GAMELOGIC_H
#define ASSIGNMENT1_GAMELOGIC_H

#include "Cell.h"
#include "Board.h"

enum Type {black, white};

enum Place {up, upRight, east, downRight, down, downLeft, west, upLeft};

class GameLogic{

public:
    virtual void playOneTurn(Board* board) = 0;
    virtual int checkScore(Cell** table, int size) = 0;
    virtual void setTurn(Type currentTurn) = 0;
    virtual Type getTurn() = 0;
    virtual bool isRunning() = 0;
    virtual Location* getPossibleMoves(Cell** table, int size) = 0;
    virtual Location* clearMoveArea(Cell** table, int size, int rowPos, int colPos, int status) = 0;
    virtual void flipDeadCell(int row, int col, Board* board) = 0;
    virtual Place whichPlace(int rowDif, int colDif) = 0;
    virtual Location* removeOneDead(Place place, int row, int col, Board* board) = 0;
    virtual bool moveExist(Location* options, Location location, int k) = 0;

private:
    //members of the class:
    Type turn;
    int running;
};

#endif //ASSIGNMENT1_GAMELOGIC_H
