//
// Created by yarin on 01/11/17.
//

#include "../include/Cell.h"
#include "../include/Location.h"
#include <iostream>

using namespace std;

/**
 * Constructor.
 * This method builds the cell.
 */
Cell::Cell(): spot(0, 0) {
    this->status = 0;
}

/**
 * destructor.
 * This method deletes the cell.
 */
Cell::~Cell() {
    //delete spot;
}

/**
 * This method returns the location of the cell.
 * @return the location of the cell.
 */
Location Cell::getSpot() {
    return this->spot;
}

/**
 * This method returns the status of the cell.
 * @return the status of the cell.
 */
int Cell::getStatus() {
    return this->status;
}

/**
 * This method updates the status.
 * @param status the status of the cell.
 */
void Cell::updateStatus(int status) {
    this->status = status;
}

/**
 * This method sets the location of the cell.
 * @param row the row of the cell.
 * @param col the column of the cell.
 */
void Cell::setSpot(int row, int col) {
    this->spot = Location(row, col);
}