//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../ConsolePlayer.h"
#include "../AIPlayer.h"
#include "BoardCreator.h"
#include "../DefaultGameLogic.h"

TEST(test_console_test, player_test) {
    Player* player = new ConsolePlayer(white);
    EXPECT_EQ(player->getPType(), Console);
    delete player;
}

TEST(test_AI_test, player_test) {
    Player* player = new AIPlayer(white);
    EXPECT_EQ(player->getPType(), AI);
    delete player;
}

TEST(test_AIboard1_test, player_test) {
    Player* player = new AIPlayer(white);
    BoardCreator* creator;
    Board* board = creator->board1();
    //board->print();
    GameLogic* logic = new DefaultGameLogic(player);
    logic->setTurn(white);
    Location* moves = logic->getPossibleMoves(board->getTable(), 8);
    player->performMove(moves, board, logic);
    EXPECT_EQ(board->getTable()[7][1].getStatus(), 2);
    EXPECT_EQ(board->getTable()[6][2].getStatus(), 2);
    EXPECT_EQ(board->getTable()[5][3].getStatus(), 2);
    delete player;
    delete board;
    delete logic;
    //delete moves;
}
