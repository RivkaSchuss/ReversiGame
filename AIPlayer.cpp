//
// Created by Rivka Schuss on 22/11/2017.
//

#include <iostream>
#include "AIPlayer.h"
using namespace std;

/**
 * Constructor.
 * This method builds a new AI Player.
 * @param type the type(X/O) of the player
 */

AIPlayer::AIPlayer(Type type) : AbstractPlayer(type), type(type) {
}

/**
 * Destructor.
 * This method deletes the player.
 */

AIPlayer::~AIPlayer() {
    delete this;
}

/**
 * This method preforms a move for an AI Player.
 * This method goes through each possible move and
 * checks its score. The move with the lowest score
 * will be chosen.
 * @param moves the list of possible moves.
 * @param board the original board.
 * @param logic the current logic of our game.
 */

void AIPlayer::performMove(Location* moves, Board* board, GameLogic* logic) {
    pType = AI;
    if (moves == NULL) {
        return;
    }
    //worstMove will hold the index of the worst possible move
    //in the list of possible moves.
    //lowestScore will hold the score of the worst possible move.
    int lowestScore = 0, currentScore = 0, worstMove = 0, l = 0;
    int size = board->getSize();
    //creating a new temporary board.
    Board* tempBoard = new Board(size, size);
    Cell** tempTable = tempBoard->getTable();
    int row = moves[l].getRow();
    int col = moves[l].getCol();
    //we'll run through all of the moves.
    while (moves[l].getRow() != 0) {
        //first we'll set the tempTable to have the current state of our original board.
        board->copyValues(tempTable);
        //trying the move.
        tempTable[row][col].updateStatus(type + 1);
        logic->flipDeadCell(row, col, tempBoard);
        //getting the result of the move.
        currentScore = logic->checkScore(tempTable, size);
        //"checkScore" calculates the result according to X.
        if (type == white) {
            currentScore = currentScore * (-1);
        }
        //we'll update our current lowest score if necessary.
        if (currentScore < lowestScore) {
            lowestScore = currentScore;
            worstMove = l;
        }
        l++;
    }
    //ultimately, we'll perform the worst move.
    row = moves[worstMove].getRow();
    col = moves[worstMove].getCol();
    board->getTable()[row][col].updateStatus(type + 1);
    logic->flipDeadCell(row, col, board);
    board->print();
    cout << "O played: " << row << "," << col << endl;
}


