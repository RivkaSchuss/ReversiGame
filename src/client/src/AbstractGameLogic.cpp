//
// Created by yarin on 06/11/17.
//

#include <iostream>
#include <limits>
#include <vector>
#include "../include/AbstractGameLogic.h"

using namespace std;

/**
 * Constructor.
 * This method build a new object of this kind.
 */
AbstractGameLogic::AbstractGameLogic() : turn(black), running(2) {}

/**
 * Destructor.
 * This method deletes an object of this kind.
 */
AbstractGameLogic::~AbstractGameLogic() {
}

/**
 * This method sets a turn.
 * Happens for example when no moves are possible for the player.
 * @param currentTurn the new player to play.
 */
void AbstractGameLogic::setTurn(Type currentTurn) {
    this->turn = currentTurn;
}

/**
 * This method returns if the game isn't over yet.
 * @return this method returns whether the game ends.
 */
bool AbstractGameLogic::isRunning() {
    return this->running;
}

/**
 * This method returns the current turn.
 * @return the current turn.
 */
Type AbstractGameLogic::getTurn() {
    return this->turn;
}

/**
 * This method checks the score at the end of the game.
 * @param table the table of the board.
 * @param size the size of the table.
 * @return the player who won.
 */
int AbstractGameLogic::checkScore(Cell **table, int size) {
    int counterBlack = 0, counterWhite = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (table[i][j].getStatus() == 1) {
                counterBlack++;
            } else if (table[i][j].getStatus() == 2){
                counterWhite++;
            }
        }
    }
    return counterBlack - counterWhite;
}

/**
 * This method is in charge of getting the possible moves.
 * This method check all of the possibilities for the next move
 * and saves it. If there are no possible moves it returns NULL.
 * @param table the table of the board.
 * @param size the size of the board.
 * @return the possible moves for this player.
 */
vector<Location> AbstractGameLogic::getPossibleMoves(Cell** table, int size) {
    //changed dynamically to be the options for the current
    // player's cell in the for loop.
    vector<Location> subOptions;
    //ultimately will store all of the options for moves.
    vector<Location> options;
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size + 1; j++) {
            if (table[i][j].getStatus() == turn + 1) {
                subOptions = this->clearMoveArea(table, size, i, j, 0);
                if (!subOptions.empty()) {
                    //l = 0;
                    for (int l = 0; l < subOptions.size(); l++) {
                        if (!moveExist(options, subOptions[l])) {
                            options.push_back(subOptions[l]);
                        }
                    }
                }
                //delete subOptions;
            }
        }
    }
    //if there are no possible moves we'll return NULL.
    if (options.empty()) {
        //delete subOptions;
        options.clear();
        return options;
    } else {
        Location option = Location(0, 0);
        //delete subOptions;
        options.push_back(option);
        //delete option;
        return options;
    }
}

/**
 * This method flips a dead cell.
 * @param row the row of the new own cell.
 * @param col the col of the new own cell.
 * @param board the board of the game.
 */

void AbstractGameLogic::flipDeadCell(int row, int col, Board* board) {
    int boardSize = board->getSize();
    int player1 = -1, player2 = -1;
    if (turn  == 0) {
        player1 = 1;
        player2 = 2;
    } else if (turn == 1){
        player1 = 2;
        player2 = 1;
    }
    int currentSign;
    int currentRow = row;
    int currentCol = col;
    int tempRow = 0;
    int tempCol = 0;
    for (int rowDirection = -1; rowDirection <= 1; rowDirection++) {
        for (int colDirection = -1; colDirection <= 1; colDirection++) {
            tempRow = currentRow + rowDirection;
            tempCol = currentCol + colDirection;
            if (currentRow >= 0 && currentRow <= boardSize && currentCol >= 0 && currentCol <= boardSize
                    && tempCol > 0 && tempCol <= boardSize && tempRow > 0 && tempRow <= boardSize) {
                currentSign = board->getTable()[tempRow][tempCol].getStatus();
                bool flag = true;
                if (rowDirection == 0 && colDirection == 0) {
                } else {
                    while (currentSign == player2 && flag) {
                        tempRow += rowDirection;
                        tempCol += colDirection;
                        if (tempRow >= 0 && tempRow <= board->getSize() && tempCol >= 0 && tempCol <= board->getSize()) {
                            if (board->getTable()[tempRow][tempCol].getStatus() == player1) {

                                flipChosenCell(tempRow, tempCol, row, col, (-1) * rowDirection, (-1) * colDirection,
                                               player1, board);
                                flag = false;
                            }
                            currentSign = board->getTable()[tempRow][tempCol].getStatus();
                        } else {
                            flag = false;
                        }
                    }
                }
            }

        }
    }
}

/**
 * This method flips a streak of locked cells.
 * @param rowOrigin the destination row.
 * @param colOrigin the destination col.
 * @param rowNew the chosen row.
 * @param colNew the chosen col.
 * @param rowDirection the direction of the row.
 * @param colDirection the direction of the column.
 * @param player1 player of the turn.
 * @param board board of the game.
 */

void AbstractGameLogic:: flipChosenCell(int rowOrigin,int colOrigin, int rowNew, int colNew,
int rowDirection, int colDirection,int player1, Board* board) {
    int currentRow = rowOrigin;
    int currentCol = colOrigin;
    currentRow += rowDirection;
    currentCol += colDirection;
    while (currentRow != rowNew || currentCol != colNew) {
        board->getTable()[currentRow][currentCol].updateStatus(player1);
        currentRow += rowDirection;
        currentCol += colDirection;
    }
}

/**
 * This method the direction of which the flip happens.
 * @param rowDif row of the new cell.
 * @param colDif col of the new cell.
 * @return returns the direction of the move.
 */
Place AbstractGameLogic::whichPlace(int rowDif, int colDif) {
    if (rowDif > 0) {
        if (colDif > 0) {
            return upLeft;
        } else if (colDif == 0) {
            return up;
        } else if (colDif < 0) {
            return upRight;
        }
    } else if (rowDif == 0) {
        if (colDif > 0) {
            return west;
        } else if (colDif < 0) {
            return east;
        }
    } else if (rowDif < 0) {
        if (colDif > 0) {
            return downLeft;
        } else if (colDif == 0) {
            return down;
        } else if (colDif < 0) {
            return downRight;
        }
    }
}

/**
 * This method flips the dead cell.
 * @param place the direction of the move.
 * @param row the row of the new cell.
 * @param col the col of the new cell.
 * @param board the board of the game.
 * @return the new flipped cell.
 */
Location* AbstractGameLogic::removeOneDead(Place place, int row, int col, Board* board) {
    int rowDead = 0, colDead = 0;
    switch(place) {
        case up:
            rowDead = row - 1;
            colDead = col;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case upRight:
            rowDead = row - 1;
            colDead = col + 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case east:
            rowDead = row;
            colDead = col + 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case downRight:
            rowDead = row + 1;
            colDead = col + 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case down:
            rowDead = row + 1;
            colDead = col;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case downLeft:
            rowDead = row + 1;
            colDead = col - 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case west:
            rowDead = row;
            colDead = col - 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        case upLeft:
            rowDead = row - 1;
            colDead = col - 1;
            board->getTable()[rowDead][colDead].
                    updateStatus(turn + 1);
            break;
        default:
            break;
    }
    Location* location = new Location(rowDead, colDead);
    return location;
}

/**
 * This method checks if the possibility is already exists.
 * @param options the current list of possible moves.
 * @param location the new possibility to be added.
 * @param k the number of possibilities for now.
 * @return wetheer the move is already exists.
 */
bool AbstractGameLogic::moveExist(vector<Location> options, Location location) {
    int l = 0;
    for (int i = 0; i < options.size(); i++) {
        if (options[i].getRow() == location.getRow() &&
                options[i].getCol() == location.getCol()) {
            return true;
        }
        l++;
    }
    return false;
}
