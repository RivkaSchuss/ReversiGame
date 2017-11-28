//
// Created by yarin on 06/11/17.
//

#include <iostream>
#include <limits>
#include "AbstractGameLogic.h"

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
    for (int i = 0; i <= size; ++i) {
        for (int j = 0; j <= size; ++j) {
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

Location* AbstractGameLogic::getPossibleMoves(Cell** table, int size) {
    //changed dynamically to be the options for the current
    // player's cell in the for loop.
    Location* subOptions;
    //ultimately will store all of the options for moves.
    Location* options = new Location(2, 2);
    int k = 0, l = 0;
    for (int i = 0; i <= size; ++i) {
        for (int j = 0; j <= size; ++j) {
            if (table[i][j].getStatus() == turn + 1) {
                subOptions = this->clearMoveArea(table, size, i, j, 0);
                if (subOptions != NULL) {
                    l = 0;
                    while (subOptions[l].getRow() != 0) {
                        if (!moveExist(options, subOptions[l], k)) {
                            options[k] = subOptions[l];
                            k++;
                        }
                        l++;
                    }
                }
            }
        }
    }
    //if there are no possible moves we'll return NULL.
    if (k == 0) {
        delete options;
        return NULL;
    } else {
        Location* option = new Location(0, 0);
        options[k] = *option;
        delete option;
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
    Location* killerOptions;
    killerOptions = clearMoveArea(board->getTable(), board->getSize(),
                                  row, col, turn + 1);
    if (killerOptions == NULL) {
        return;
    } else {
        int l = 0;
        int rowDif = 0, colDif = 0;
        Location *flipped;
        while (killerOptions[l].getRow() != 0) {
            rowDif = row - killerOptions[l].getRow();
            colDif = col - killerOptions[l].getCol();
            Place place = whichPlace(rowDif, colDif);
            flipped = removeOneDead(place, row, col, board);
            flipDeadCell(flipped->getRow(), flipped->getCol(), board);
            l++;
            delete flipped;
        }
    }
}

Place AbstractGameLogic::eatenFrom(Board* board, int rowOrigin, int colOrigin, int rowNew, int colNew) {
    Cell** table = board->getTable();
    int size = board->getSize();
    if (rowOrigin - 2 > 0 || rowOrigin + 2 <= size) {
        //checking the upper side
        if (rowOrigin - 2 > 0) {
            if (table[rowOrigin - 1][colOrigin].getStatus() != this->turn + 1
                && table[rowOrigin - 1][colOrigin].getStatus() > 0) {
                if (table[rowOrigin - 2][colOrigin].getStatus() == turn + 1) {
                    if (rowOrigin - 2 == rowNew && colOrigin == colNew) {
                        return down;
                    }
                }
            }
        }
        //checking the lower side
        if (rowOrigin + 2 <= size){
            if (table[rowOrigin + 1][colOrigin].getStatus() != this->turn + 1
                && table[rowOrigin + 1][colOrigin].getStatus() > 0) {
                if (table[rowOrigin + 2][colOrigin].getStatus() == turn + 1) {
                    if (rowOrigin + 2 == rowNew && colOrigin == colNew) {
                        return up;
                    }
                }
            }
        }
    }
    if (rowOrigin - 2 > 0 || rowOrigin + 2 <= size
        || colOrigin - 2 > 0 || colOrigin + 2 <= size) {
        //checking the upper left side
        if (rowOrigin - 2 > 0 && colOrigin - 2 > 0) {
            if (table[rowOrigin - 1][colOrigin - 1].getStatus() != this->turn + 1
                && table[rowOrigin - 1][colOrigin - 1].getStatus() > 0) {
                if (table[rowOrigin - 2][colOrigin - 2].getStatus() == turn + 1) {
                    if (rowOrigin - 2 == rowNew && colOrigin - 2 == colNew) {
                        return downRight;
                    }
                }
            }
        }
        //checking the upper right side
        if (rowOrigin - 2 > 0 && colOrigin + 2 <= size) {
            if (table[rowOrigin - 1][colOrigin + 1].getStatus() != this->turn + 1
                && table[rowOrigin - 1][colOrigin + 1].getStatus() > 0) {
                if (table[rowOrigin - 2][colOrigin + 2].getStatus() == turn + 1) {
                    if (rowOrigin - 2 == rowNew && colOrigin + 2 == colNew) {
                        return downLeft;
                    }
                }
            }
        }
        //checking the lower left side
        if (rowOrigin + 2 <= size && colOrigin - 2 > 0) {
            if (table[rowOrigin + 1][colOrigin - 1].getStatus() != this->turn + 1
                && table[rowOrigin + 1][colOrigin - 1].getStatus() > 0) {
                if (table[rowOrigin + 2][colOrigin - 2].getStatus() == turn + 1) {
                    if (rowOrigin + 2 == rowNew && colOrigin - 2 == colNew) {
                        if (rowOrigin + 2 == rowNew && colOrigin - 2 == colNew) {
                            return upRight;
                        }
                    }
                }
            }
        }
        //checking the lower right side
        if (rowOrigin + 2 <= size && colOrigin + 2 <= size) {
            if (table[rowOrigin + 1][colOrigin + 1].getStatus() != this->turn + 1
                && table[rowOrigin + 1][colOrigin + 1].getStatus() > 0) {
                if (table[rowOrigin + 2][colOrigin + 2].getStatus() == turn + 1) {
                    if (rowOrigin + 2 == rowNew && colOrigin + 2 == colNew) {
                        return upLeft;
                    }
                }
            }
        }
    }
    if (colOrigin - 2 > 0 || colOrigin + 2 <= size) {
        //checking the left side
        if (colOrigin - 2 > 0) {
            if (table[rowOrigin][colOrigin - 1].getStatus() != this->turn + 1
                && table[rowOrigin][colOrigin - 1].getStatus() > 0) {
                if (table[rowOrigin][colOrigin - 2].getStatus() == turn + 1) {
                    if (rowOrigin == rowNew && colOrigin - 2 == colNew) {
                        return east;
                    }
                }
            }
        }
        //checking the right side
        if (colOrigin + 2 <= size) {
            if (table[rowOrigin][colOrigin + 1].getStatus() != this->turn + 1
                && table[rowOrigin][colOrigin + 1].getStatus() > 0) {
                if (table[rowOrigin][colOrigin + 2].getStatus() == turn + 1) {
                    if (rowOrigin == rowNew && colOrigin + 2 == colNew) {
                        return west;
                    }
                }
            }
        }
    }
    return none;
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

bool AbstractGameLogic::moveExist(Location *options, Location location, int k) {
    int l = 0;
    while (l <= k) {
        if (options[l].getRow() == location.getRow() &&
                options[l].getCol() == location.getCol()) {
            return true;
        }
        l++;
    }
    return false;
}
