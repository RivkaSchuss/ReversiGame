//
// Created by Rivka Schuss on 28/11/2017.
//

#include "BoardCreator.h"

/**
 * creates a board.
 * @return a board with specific moves already played.
 */
Board* BoardCreator::board1() {
    Board* board = new Board(8);
    Cell** table = board->getTable();
    table[3][3].updateStatus(2);
    table[3][4].updateStatus(2);
    table[3][5].updateStatus(2);
    table[4][3].updateStatus(2);
    table[4][5].updateStatus(2);
    table[5][3].updateStatus(1);
    table[6][2].updateStatus(1);
    table[6][6].updateStatus(2);
    table[5][5].updateStatus(1);
    table[5][6].updateStatus(1);
    table[6][5].updateStatus(1);
    return board;
}

/**
 * creates a board.
 * @return a board with specific moves already played.
 */
Board* BoardCreator::board2() {
    Board* board = new Board(8);
    Cell** table = board->getTable();
    table[4][3].updateStatus(1);
    table[4][4].updateStatus(1);
    table[6][5].updateStatus(2);
    table[6][6].updateStatus(2);
    table[7][5].updateStatus(2);
    return board;
}

Board* BoardCreator::board3() {
    Board* board = new Board(8);

    return board;
}

BoardCreator::~BoardCreator() {

}