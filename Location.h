//
// Created by yarin on 01/11/17.
//

#ifndef ASSIGNMENT1_LOCATION_H
#define ASSIGNMENT1_LOCATION_H


class Location {

public:
    //the constructor
    Location(int row, int col);
    //the destructor
    ~Location();
    int getRow();
    int getCol();

private:
    //the members of the class:
    int row;
    int col;
};


#endif //ASSIGNMENT2_LOCATION_H
