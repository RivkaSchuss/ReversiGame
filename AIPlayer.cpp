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
    pType = AI;
}

/**
 * Destructor.
 * This method deletes the player.
 */

AIPlayer::~AIPlayer() {
    //delete this;
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
    if (moves == NULL) {
        return;
    }
    int currentScore = 0, bestWorstScore = 0, bestWorstIndex = 0, l = 0, k = 0, currentWorst = 0;
    int size = board->getSize();
    //creating a new temporary board.
    Board* tempBoard = new Board(size);
    Cell** tempTable = tempBoard->getTable();
    Board* tempBoard1 = new Board(size);
    Cell** tempTable1 = tempBoard->getTable();

    int row,col;
    //we'll run through all of the moves.
    while (moves[l].getRow() != 0) {
        row = moves[l].getRow();
        col = moves[l].getCol();
        //first we'll set the tempTable to have the current state of our original board.
        board->copyValues(tempTable);
        //trying the move.
        tempTable[row][col].updateStatus(type + 1);
        logic->flipDeadCell(row, col, tempBoard);
        if (type == black) {
            logic->setTurn(white);
        } else {
            logic->setTurn(black);
        }
        Location* rivalMoves = logic->getPossibleMoves(tempTable, size);
        k = 0;
        while (rivalMoves[k].getRow() != 0) {
            row = rivalMoves[k].getRow();
            col = rivalMoves[k].getCol();
            tempBoard->copyValues(tempTable1);
            tempTable1[row][col].updateStatus(type + 1);
            logic->flipDeadCell(row, col, tempBoard1);
            currentScore = logic->checkScore(tempTable1, size);
            if (type == white) {
                currentScore = (-1) * currentScore;
            }
            if (currentScore < currentWorst) {
                currentWorst = currentScore;
            }
            //cout << currentScore << endl;
            k++;
        }
        if (type == black) {
            logic->setTurn(white);
        } else {
            logic->setTurn(black);
        }
        if (currentWorst > bestWorstScore) {
            bestWorstScore = currentWorst;
            bestWorstIndex = l;
        }
        l++;
    }
    delete tempBoard;
    if (type == black) {
        logic->setTurn(white);
    } else {
        logic->setTurn(black);
    }
    //ultimately, we'll perform the worst move.
    row = moves[bestWorstIndex].getRow();
    col = moves[bestWorstIndex].getCol();
    //update status of the new cells
    board->getTable()[row][col].updateStatus(type + 1);
    logic->flipDeadCell(row, col, board);
    board->print();
    cout << "O played " << row << "," << col << endl;
}

PlayerType AIPlayer::getPType() {
    return this->pType;
}


