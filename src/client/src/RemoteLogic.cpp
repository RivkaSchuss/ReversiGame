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
#include <sstream>
#include "../include/RemoteLogic.h"

#define ASCII_DIFF 48

using namespace std;

/**
 * constructor.
 * @param secondPlayer the second player.
 * @param client the client.
 */
RemoteLogic::RemoteLogic(Player* secondPlayer, Client* client) : DefaultGameLogic(secondPlayer),
                                                                           client(client){
    notFirstTurn = 0;
    if (client->getType() == first) {
        turn = black;
    } else {
        turn = white;
    }
    flag = false;
}

/**
 * destructor.
 */
RemoteLogic::~RemoteLogic() {
    delete client;
}

/**
 * plays one turn of the game.
 * @param board the game board.
 */
void RemoteLogic::playOneTurn(Board *board) {
    int row, col, l = 0;
    int status, opponent;
    //initaling the status and opponent
    if (client->getType() == first) {
        status = black;
        opponent = white;
    } else {
        status = white;
        opponent = black;
    }
    //if we can play with the client.
    vector<Location> moves;
    if (client->getAvailable()) {
        cout << endl;
        board->print();
        bool moveCompleted = false;
        while (!moveCompleted) {
            l = 0;
            moves = getPossibleMoves(board->getTable(), board->getSize());
            if (moves.empty()) {
                running -= 1;
                if (client->getType() == first) {
                    cout << "X: You have no possible moves!" << endl;
                    //if the game is over, we send the server "end"
                    if (running == 0 || flag) {
                        char nomove[4096] = "End";
                        write(client->getSocket(), nomove, sizeof(nomove));
                    } else {
                        //if there are no more moves, we send the server "NoMove"
                        char nomove[4096] = "NoMove";
                        write(client->getSocket(), nomove, sizeof(nomove));
                    }
                    return;
                } else {
                    cout << "O: You have no possible moves!" << endl;
                    if (running == 0 || flag) {
                        char nomove[4096] = "End";
                        write(client->getSocket(), nomove, sizeof(nomove));
                    } else {
                        char nomove[4096] = "NoMove";
                        write(client->getSocket(), nomove, sizeof(nomove));
                    }
                    return;
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
            cout << "Please enter your move: play row,col:" << endl;
            char dummy[20];
            cin >> dummy >> row >> col;
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
        //we write to the other client what we've played
        int send_bytes = write(client->getSocket(), player, sizeof(player));
        
        if (notFirstTurn  == 1) {
            send_bytes = write(client->getSocket(), player, sizeof(player));
        }
        
        if (send_bytes < 0) {
            cout << "Error writing to client." << endl;
            return;
        }
    } else {
        cout << "Waiting for other player's move..." << endl;
        char buffer[4096];
        //we read what the other player has played
        int read_bytes = read(client->getSocket(), buffer, sizeof(buffer));
        if (read_bytes < 0) {
            cout << "Error reading from server." << endl;
            return;
        }
        if (strcmp(buffer, "end") == 0) {
            flag = true;
            moves.clear();
            running = 0;
            //exit(0);
            //char nomove[4096] = "End";
            //write(client->getSocket(), nomove, sizeof(nomove));
        }
        //converting the strings to ints.
        int iRow = (int) buffer[10] - ASCII_DIFF;
        int iCol = (int) buffer[13] - ASCII_DIFF;
        //cout << iRow << " " << iCol << endl;
        if (iRow != 0 - ASCII_DIFF) {
            //we print the other player's move
            cout << buffer << endl;
            //update the status of the move played
            board->getTable()[iRow][iCol].updateStatus(opponent + 1);
            if (status == black) {
                turn = white;
            } else {
                turn = black;
            }
            //flip the board according to what has been played
            flipDeadCell(iRow, iCol, board);
        }
        client->updateTurn(true);
    }
}

/**
 * converts ints to strings.
 * @param num the int to convert.
 * @return the int in string form.
 */
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
