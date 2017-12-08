//
// Created by Rivka Schuss on 05/12/2017.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "../include/RemoteLogic.h"

using namespace std;

RemoteLogic::RemoteLogic(Player* secondPlayer, Client* client) : DefaultGameLogic(secondPlayer),
                                                                           client(client){
    notFirstTurn = 0;
    if (client->getType() == first) {
        turn = black;
    } else {
        turn = white;
    }
}

RemoteLogic::~RemoteLogic() {
    delete client;
}

void RemoteLogic::playOneTurn(Board *board) {
    int row, col, l = 0;
    int status, opponent;
    if (client->getType() == first) {
        status = black;
        opponent = white;
    } else {
        status = white;
        opponent = black;
    }
    if (client->getAvailable()) {
        cout << endl;
        board->print();
        bool moveCompleted = false;
        vector<Location> moves;
        while (!moveCompleted) {
            l = 0;
            moves = getPossibleMoves(board->getTable(), board->getSize());
            if (moves.empty()) {
                running -= 1;
                char nomove[20] = "NoMove";
                if (client->getType() == first) {
                    cout << "X: You have no possible moves!" << endl;
                    write(client->getSocket(), nomove, sizeof(nomove));
                    turn = white;
                    //return;
                } else {
                    cout << "O: You have no possible moves!" << endl;
                    write(client->getSocket(), nomove, sizeof(nomove));
                    turn = black;
                    //return;
                    //cout << "O: You have no possible moves!" << endl;
                    //return;
                }
            }
            running = 2;
            if (client->getType() == first) {
                cout << "X: It's your move." << endl;
            } else {
                cout << "O: It's your move." << endl;
            }
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
                    board->getTable()[row][col].updateStatus(status + 1);
                    flipDeadCell(row, col, board);
                    moveCompleted = true;
                }
                l++;
            }
            if (!moveCompleted) {
                cout << "This isn't an option" << endl;
                board->print();
            } else {
                board->print();
            }
            notFirstTurn++;
            //delete moves;
        }
        char player[4096];
        client->updateTurn(false);
        string sRow = intToString(row);
        string sCol = intToString(col);
        if (client->getType() == first) {
            string move = "X played: " + sRow + ", " + sCol;
            strcpy(player, move.c_str());
        } else {
            string move = "0 played: " + sRow + ", "+ sCol;
            strcpy(player, move.c_str());
        }
        //cout << player << endl;
        int send_bytes = write(client->getSocket(), player, sizeof(player));
        if (send_bytes < 0) {
            cout << "Error writing to client." << endl;
            return;
        }

        //delete player;
    } else {
        cout << "Waiting for other player's move..." << endl;
        char buffer[4096];
        int read_bytes = read(client->getSocket(), buffer, sizeof(buffer));
        if (read_bytes < 0) {
            cout << "Error reading from server." << endl;
            return;
        }
        cout << buffer << endl;
        int iRow = (int) buffer[10] - 48;
        int iCol = (int) buffer[13] - 48;
        //cout << iRow << " " << iCol << endl;
        board->getTable()[iRow][iCol].updateStatus(opponent + 1);
        if (status == black) {
            turn = white;
        } else {
            turn = black;
        }
        flipDeadCell(iRow, iCol, board);
        /*
        if (turn == black) {
            turn = white;
        } else {
            turn = black;
        }
         */
        client->updateTurn(true);
    }
}

string RemoteLogic::intToString(int num) {
    if (num == 0) {
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else if (num == 2) {
        return "2";
    }
    else if (num == 3) {
        return "3";
    }
    else if (num == 4) {
        return "4";
    }
    else if (num == 5) {
        return "5";
    }
    else if (num == 6) {
        return "6";
    }
    else if (num == 7) {
        return "7";
    }
    else if (num == 8) {
        return "8";
    }
    else if (num == 9) {
        return "9";
    }
}
