//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_ABSTRACTGAMELOGIC_H
#define ASSIGNMENT1_ABSTRACTGAMELOGIC_H


#include "GameLogic.h"

class AbstractGameLogic : public GameLogic {

public:
    AbstractGameLogic();
    ~AbstractGameLogic();
    virtual void playOneTurn(Board* board) = 0;
    int checkScore(Cell** table, int size);
    void setTurn(Type currentTurn);
    Type getTurn();
    bool isRunning();
    Location* getPossibleMoves(Cell** table, int size);
    virtual Location* clearMoveArea(Cell** table, int size, int rowPos, int colPos, int status) = 0;
    void flipDeadCell(int row, int col, Board* board);
    Place whichPlace(int rowDif, int colDif);
    Location* removeOneDead(Place place, int row, int col, Board* board);
    bool moveExist(Location* options, Location location, int k);
    virtual int getNotFirstTurn() = 0;
    Place eatenFrom(Board* board,int rowOrigin, int colOrigin, int rowNew, int colNew);


protected:
    //the members of the class
    Type turn;
    int running;
    int notFirstTurn;

};


#endif //ASSIGNMENT1_ABSTRACTGAMELOGIC_H
