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
    Board* board = new Board(8);
    cout << "Welcome to Reversi!" << endl;
    cout << "Please choose a player type, a for AI, and c for console:" << endl;
    Player* blackPlayer = new ConsolePlayer(black);
    char choice;
    cin >> choice;
    Player* whitePlayer;
    switch (choice) {
        case 'a' :
            whitePlayer =  new AIPlayer(white);
            break;
        case 'c':
            whitePlayer = new ConsolePlayer(white);
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
