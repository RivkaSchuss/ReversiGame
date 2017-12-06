//
// Created by yarin on 06/11/17.
//

#include <iostream>
#include <cstdlib>
#include "../include/Game.h"
#include "../include/DefaultGameLogic.h"
#include "../include/RemotePlayer.h"
#include "../include/ConsolePlayer.h"
#include "../include/RemoteLogic.h"
#include "../include/Server.h"

using namespace std;

/**
 * The constructor.
 * @param blackPlayer the 'X' player.
 * @param whitePlayer the 'O' player.
 * @param board the board of the game.
 * @param logic the game logic of the game.
 */
Game::Game() {}

/**
 * The destructor.
 */
Game::~Game() {
}

void Game::runMenu() {
    int choice, choiceSize;
    cout << "Welcome to Reversi!" << endl;
    cout << "Please choose your board size: 4 or 8." << endl;
    cin >> choiceSize;
    Board* board;
    switch(choiceSize) {
        case 4:
            board = new Board(4);
            break;
        case 8:
            board = new Board(8);
            break;
        default:
            cout << "Not an option." << endl;
            break;
    }
    Player* whitePlayer;
    GameLogic* logic;
    int chosen = 0;
    while (chosen != 1) {
        cout << "Please choose a player type: " << endl;
        cout << "1. Console Player " << endl; cout << "2. AI Player " << endl;cout << "3. Remote Player " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                whitePlayer = new ConsolePlayer(white);
                chosen = 1;
                logic = new DefaultGameLogic(whitePlayer);
                break;
            case 2:
                whitePlayer = new AIPlayer(white);
                chosen = 1;
                logic = new DefaultGameLogic(whitePlayer);
                break;
            case 3:
                initConnection();
                whitePlayer = new RemotePlayer(white, server);
                chosen = 1;
                logic = new RemoteLogic(whitePlayer);
                break;
            default:
                cout << "Not an option." << endl;
                break;
        }
    }
    runGame(board, logic);
    delete whitePlayer;
}

/**
 * This method runs the game loop.
 */
void Game::runGame(Board* board, GameLogic* logic) {
    if(logic->getNotFirstTurn() == 0) {
        board->print();
    }
    while (logic->isRunning() != 0) {
        //board->print();
        cout << endl;
        logic->playOneTurn(board);
        if (logic->getTurn() == black) {
            logic->setTurn(white);
        } else {
            logic->setTurn(black);
        }
    }
    if (logic->checkScore(board->getTable(), board->getSize()) >= 1) {
        cout << "X: Congrats, you win!" << endl;
    } else if (logic->checkScore(board->getTable(), board->getSize()) <= -1) {
        cout << "O: Congrats, you win!" << endl;
    } else {
        cout << "It's a TIE!" << endl;
    }
    delete board;
    delete logic;
}

void Game::initConnection() {
    server = new Server(1500);
    try {
        server->start();
    } catch(const char* msg) {
        cout << "Cannot start server." << msg <<  endl;
        exit(-1);
    }
}
