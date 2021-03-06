//
// Created by yarin on 24/10/17.
//

#ifndef ASSIGNMENT1_BOARD_H
#define ASSIGNMENT1_BOARD_H


#include "Cell.h"

class Board {
public:
    //constructor
    Board(int size);
    //prints the current state
    void print();
    //deletes the table
    ~Board();
    Cell** getTable();
    int getSize();
    void copyValues(Cell** table);

private:
    //members of the class:
    Cell** table;
    int size;
};


#endif //ASSIGNMENT1_BOARD_H
