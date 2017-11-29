#include <iostream>
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/ConsolePlayer.h"
#include "../include/Game.h"
#include "../include/DefaultGameLogic.h"
#include "../include/AIPlayer.h"

using namespace std;

/**
 * the main.
 * @param argc the number of arguments.
 * @param argv the arguments.
 * @return 0.
 */
int main(int argc, char* argv[]) {
    Board* board = new Board(8);
    cout << "Welcome to Reversi!" << endl;
    cout << "Please choose a player type: " << endl;
    cout << "1. Console Player " << endl; cout << "2. AI Player " << endl;
    Player* blackPlayer = new ConsolePlayer(black);
    int choice;
    cin >> choice;
    Player* whitePlayer;
    switch (choice) {
        case 1:
            whitePlayer =  new ConsolePlayer(white);
            break;
        case 2:
            whitePlayer = new AIPlayer(white);
            break;
        default:
            cout << "Not an option." << endl;
            break;
    }
    GameLogic* logic = new DefaultGameLogic(whitePlayer);
    Game* game = new Game(blackPlayer, whitePlayer, board, logic);
    game->run();
    delete game;
    return 0;
}
