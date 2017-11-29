//
// Created by yarin on 06/11/17.
//

#ifndef ASSIGNMENT1_ABSTRACTGAMELOGIC_H
#define ASSIGNMENT1_ABSTRACTGAMELOGIC_H


#include "GameLogic.h"
#include <vector>

using namespace std;

class AbstractGameLogic : public GameLogic {

public:
    AbstractGameLogic();
    ~AbstractGameLogic();
    virtual void playOneTurn(Board* board) = 0;
    int checkScore(Cell** table, int size);
    void setTurn(Type currentTurn);
    Type getTurn();
    bool isRunning();
    vector<Location> getPossibleMoves(Cell** table, int size);
    virtual vector<Location> clearMoveArea(Cell** table, int size, int rowPos, int colPos, int status) = 0;
    void flipDeadCell(int row, int col, Board* board);
    Place whichPlace(int rowDif, int colDif);
    Location* removeOneDead(Place place, int row, int col, Board* board);
    bool moveExist(vector<Location> options, Location location);
    virtual int getNotFirstTurn() = 0;
    Place eatenFrom(Board* board,int rowOrigin, int colOrigin, int rowNew, int colNew);


protected:
    //the members of the class
    Type turn;
    int running;
    int notFirstTurn;

};


#endif //ASSIGNMENT1_ABSTRACTGAMELOGIC_H
