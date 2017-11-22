//
// Created by yarin on 06/11/17.
//

#include <iostream>
#include "Game.h"
using namespace std;

/**
 * The constructor.
 * @param blackPlayer the 'X' player.
 * @param whitePlayer the 'O' player.
 * @param board the board of the game.
 * @param logic the game logic of the game.
 */

Game::Game(Player* blackPlayer, Player* whitePlayer, Board* board, GameLogic* logic) :
        blackPlayer(blackPlayer), whitePlayer(whitePlayer), board(board), logic(logic) {
}

/**
 * The destructor.
 */

Game::~Game() {
    delete blackPlayer;
    delete whitePlayer;
    delete board;
    delete logic;
    delete this;
}

/**
 * This method runs the game loop.
 */

void Game::run() {
    while (logic->isRunning() != 0) {
        board->print();
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
}