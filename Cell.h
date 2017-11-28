//
// Created by yarin on 01/11/17.
//

#ifndef ASSIGNMENT1_CELL_H
#define ASSIGNMENT1_CELL_H

#include "Location.h"

class Cell {
public:
    Cell();
    ~Cell();
    Location getSpot();
    int getStatus();
    void updateStatus(int status);
    void setSpot(int row, int col);

private:
    //members
    Location spot;
    int status;
    //status = 0 means empty
    //status = 1 means the cell is marked X
    //status = 2 means the cell is marked O
};


#endif //ASSIGNMENT2_CELL_H
