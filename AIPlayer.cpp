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
        //delete moves;
        return;
    }
    //the size of the board.
    int size = board->getSize();
    //the score of the AI according to the rivals move.
    int currentScore = 0;
    //the worst score of the given AI player move.
    int currentWorst = 0;
    //the index of the bestWorst move in AIs list.
    int bestWorstIndex = 0;
    //the score of the bestWorst move.
    int bestWorstScore = (-1) * size * size;
    //the temporary board and table for AI
    Board* tempBoard = new Board(size);
    Cell** tempTable = tempBoard->getTable();
    //the temporary board and table for the rivals move.
    Board* tempBoardRival = new Board(size);
    Cell** tempTableRival = tempBoardRival->getTable();
    //number of moves for AI.
    int l = 0;
    //number of moves for AI.
    int k = 0;
    //row and col of the move.
    int row = 0, col = 0;
    //will hold the rival moves.
    Location* rivalMoves;
    //we'll go through all of the AI moves.
    while (moves[l].getRow() != 0) {
        //resetting the temporary table.
        board->copyValues(tempTable);
        //simple way to use row and col.
        row = moves[l].getRow();
        col = moves[l].getCol();
        //operating the move on the temporary board.
        tempTable[row][col].updateStatus(type + 1);
        logic->flipDeadCell(row,col,tempBoard);
        //we'll get the current possible moves for the rival.
        //first, we need to change the turn.
        if (logic->getTurn() == black) {
            logic->setTurn(white);
        } else {
            logic->setTurn(black);
        }
        //now we'll get the moves for the rival.
        rivalMoves = logic->getPossibleMoves(tempTable,size);
        if (rivalMoves == NULL) {
            board->getTable()[row][col].updateStatus(type + 1);
            logic->flipDeadCell(row,col,board);
            if (type == black) {
                cout << "X played (" << row << "," << col << ")" << endl;
            } else {
                cout << "O played (" << row << "," << col << ")" << endl;
            }
            //delete tempBoard;
            //delete tempBoardRival;
            //delete moves;
            return;
        }
        //reset the index of the list
        k = 0;
        //reset the current worst score.
        currentWorst = size * size;
        //we'll go through each of the rivals move for our current AI move.
        //cout << "move:" << row << " " << col << endl;
        while (rivalMoves[k].getRow() != 0) {
            //resetting the temporary "rival" table.
            tempBoard->copyValues(tempTableRival);
            //simple way to use row and col.
            row = rivalMoves[k].getRow();
            col = rivalMoves[k].getCol();
            //operating the move on the temporary "rival" board.
            tempTableRival[row][col].updateStatus(logic->getTurn() + 1);
            logic->flipDeadCell(row,col,tempBoardRival);
            //getting the current result. we multiply it by -1 because it's the score for the rival.
            currentScore = (-1) * logic->checkScore(tempTableRival, size);
            //if this score is lower than our current worst score we'll update our current worst score.
            //cout << row << " " << col << " " << currentScore << endl;
            //tempBoardRival->print();
            if (currentScore < currentWorst) {
                currentWorst = currentScore;
            }
            //moving to the next rival possible move.
            k++;
        }
        //we'll check if the worst outcome of our current move is the best we can have so far.
        if (currentWorst > bestWorstScore) {
            bestWorstScore = currentWorst;
            bestWorstIndex = l;
        }
        //we need to return to be the AI player.
        if (logic->getTurn() == black) {
            logic->setTurn(white);
        } else {
            logic->setTurn(black);
        }
        //moving to the next AI possible move.
        l++;
    }
    //ultimately, we'll perform the worst move.
    row = moves[bestWorstIndex].getRow();
    col = moves[bestWorstIndex].getCol();
    board->getTable()[row][col].updateStatus(type + 1);
    logic->flipDeadCell(row, col, board);
    board->print();
    //we'll inform the move.
    if (type == black) {
        cout << "X played (" << row << "," << col << ")" << endl;
    } else {
        cout << "O played (" << row << "," << col << ")" << endl;
    }
    //delete tempBoard;
    //delete tempBoardRival;
    //delete moves;
    //delete rivalMoves;
}

PlayerType AIPlayer::getPType() {
    return this->pType;
}


