#include <iostream>
#include "Board.h"
#include "Player.h"
#include "ConsolePlayer.h"
#include "Game.h"
#include "DefaultGameLogic.h"

using namespace std;

int main() {
    //creating a new 8X8 board
    Board* board = new Board(8,8);
    GameLogic* logic = new DefaultGameLogic();
    Player* whitePlayer = new ConsolePlayer(white);
    Player* blackPlayer = new ConsolePlayer(black);
    Game* game = new Game(blackPlayer, whitePlayer, board, logic);
    game->run();
    return 0;
}
