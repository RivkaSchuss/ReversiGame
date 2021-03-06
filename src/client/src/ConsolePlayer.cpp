//
// Created by yarin on 03/11/17.
//

#include <iostream>
#include <limits>
#include "../include/ConsolePlayer.h"
#include <vector>

using namespace std;

/**
 * Constructor.
 * @param type the type of the player.
 */
ConsolePlayer::ConsolePlayer(Type type) : AbstractPlayer(type), type(type){
    pType = Console;
}

/**
 * Destructor.
 */
ConsolePlayer::~ConsolePlayer() {
    //delete this;
}

/**
 * performs a move for the player.
 * @param moves the list of possible moves.
 * @param board the game board.
 * @param logic the game logic.
 */
void ConsolePlayer::performMove(vector<Location> moves, Board* board, GameLogic* logic) {
    if (moves.empty()) {
        cout << "O: You have no possible moves!" << endl;
        board->print();
        return;
    }
    bool moveCompleted = false;
    int row, col, l = 0;
    cout << "O: It's your move." << endl;
    cout << "Your possible moves: ";
    while (moves[l].getRow() != 0) {
        cout << "(" << moves[l].getRow() << "," << moves[l].getCol() << ") ";
        l++;
    }
    cout << endl;
    cout << "Please enter your move row,col:" << endl;
    cin >> row >> col;
    //validating the input.
    while (!cin) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Input isn't valid. Please enter your move row,col:" << endl;
        cin >> row >> col;
    }
    l = 0;
    while (moves[l].getRow() != 0) {
        if (row == moves[l].getRow() && col == moves[l].getCol()) {
            board->getTable()[row][col].updateStatus(white + 1);
            logic->flipDeadCell(row, col, board);
            moveCompleted = true;
        }
        l++;
    }
    if (!moveCompleted) {
        cout << "This isn't an option" << endl;
        board->print();
        //return;
    }
    if (moveCompleted) {
        board->print();
    }
}

/**
 * returns the current player type.
 * @return an enum with the current player type.
 */
PlayerType ConsolePlayer::getPType() {
    return this->pType;
}


