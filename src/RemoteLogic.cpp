//
// Created by Rivka Schuss on 05/12/2017.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "../include/RemoteLogic.h"

using namespace std;

RemoteLogic::RemoteLogic(Player *secondPlayer, Server* server) : secondPlayer(secondPlayer),
                                                                 DefaultGameLogic(secondPlayer), server(server){
    notFirstTurn = 0;
}

RemoteLogic::~RemoteLogic() {
    delete secondPlayer;
}

void RemoteLogic::playOneTurn(Board *board) {
    int row, col, l = 0;
    bool moveCompleted = false;
    vector<Location> moves;
    while (!moveCompleted) {
        l = 0;
        moves = getPossibleMoves(board->getTable(), board->getSize());
        if (moves.empty()) {
            running -= 1;
            if (turn == black) {
                cout << "X: You have no possible moves!" << endl;
                return;
            } else {
                secondPlayer->performMove(moves, board, this);
                return;
                //cout << "O: You have no possible moves!" << endl;
                //return;
            }
        }
        running = 2;
        if (turn == black) {
            cout << "X: It's your move." << endl;
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
            for (int i = 0; i < moves.size(); i++) {
                if (row == moves[i].getRow() && col == moves[i].getCol()) {
                    board->getTable()[row][col].updateStatus(black + 1);
                    flipDeadCell(row, col, board);
                    moveCompleted = true;
                }
                l++;
            }
            if (!moveCompleted) {
                cout << "This isn't an option" << endl;
                board->print();
            }else {
                board->print();
            }
            notFirstTurn++;
        } else {
            cout << "Waiting for the other player's move.." << endl;
            secondPlayer->performMove(moves, board, this);
            return;
            //cout << "O: It's your move." << endl;
        }
        //delete moves;
    }
}
