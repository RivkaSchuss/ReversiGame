#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Board.h"
#include "Player.h"
#include "ConsolePlayer.h"
#include "Game.h"
#include "DefaultGameLogic.h"
#include "AIPlayer.h"

using namespace std;

int main(int argc, char* argv[]) {
    Board* board = new Board(4);
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
