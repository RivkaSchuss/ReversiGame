//
// Created by yarin on 01/11/17.
//

#include "../include/Location.h"


#include <iostream>

using namespace std;

/**
 * Constructor.
 * This method builds a location object.
 * @param col the column of the location.
 * @param row the row of the location.
 */
Location::Location(int row, int col) : row(row), col(col){}

/**
 * destructor.
 * This method deletes a location object.
 */
Location::~Location() {
}

/**
 * This method returns the col location.
 * @return the col location.
 */
int Location::getCol() {
    return this->col;
}

/**
 * This method returns the row location.
 * @return the row location.
 */
int Location::getRow() {
    return this->row;
}

