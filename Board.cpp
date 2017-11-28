//
// Created by yarin on 24/10/17.
//

#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "GameLogic.h"

using namespace std;

/**
 * Constructor.
 * This method builds the board.
 * @param width  the width of the table.
 * @param height the height of the table.
 */

Board::Board(int size) : size(size) {
    //creating a 2-dimensional array as the table.
    table = new Cell*[size + 1];
    for (int i = 0; i < size + 1; ++i) {
        table[i] = new Cell[size + 1];
    }
    for (int i = 0; i < size + 1; ++i) {
        for (int j = 0; j < size + 1; ++j) {
            table[i][j].setSpot(i, j);
        }
    }
    table[size / 2][size / 2].updateStatus(2);
    table[size / 2][size / 2 + 1].updateStatus(1);
    table[size / 2 + 1][size / 2].updateStatus(1);
    table[size / 2 + 1][size / 2 + 1].updateStatus(2);
}

/**
 * This method print the table at its current state.
 */

void Board::print() {
    for (int i = 0; i < size * 2 + 2 ; ++i) {
        if (i % 2 == 0) {
            if (i > 1 && i % 2 == 0) {
                cout << (i - 2) / 2 + 1;
            }
            if (i == 0) {
                cout << " ";
            }
            for (int j = 0; j < size + 1; ++j) {
                cout << "| ";
                if (i == 0 && j != size) {
                    cout << j + 1 << " ";
                } else if (i > 1 && i <= 16) {
                    if (table[i / 2][j + 1].getStatus() == 1
                        || table[i / 2][j + 1].getStatus() == 2) {
                        if (table[i / 2][j + 1].getStatus() == 1) {
                            cout << "X ";
                        } else if (table[i / 2][j + 1].getStatus() == 2) {
                            cout << "O ";
                        }
                    } else {
                        cout << "  ";
                    }
                } else {
                    cout << "  ";
                }
            }
        } else {
            cout << "-";
            for (int j = 0; j < size * 4.125; ++j) {
                cout << "-";
            }
        }
        //going a line down.
        cout << endl;
    }
}

/**
 * This method delete the table.
 */

Board:: ~Board() {
    for (int i = 0; i < size + 1; i++) {
        delete[] table[i];
    }
    delete[] table;
    //delete this;
}

/**
 * This method returns the table.
 * @return the table.
 */

Cell** Board::getTable() {
    return this->table;
}

/**
 * This method returns the size of the table.
 * @return the size of the table.
 */

int Board::getSize() {
    return this->size;
}

/**
 * This method copies the value of a board to a given table.
 * @param table to have the values.
 */

void Board::copyValues(Cell** table) {
    Cell* currentCell = new Cell();
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            (*(currentCell)).setSpot(i, j);
            (*(currentCell)).updateStatus(this->table[i][j].getStatus());
            table[i][j] = *currentCell;
        }
    }
    delete currentCell;
}