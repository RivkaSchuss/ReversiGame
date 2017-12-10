//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../include/ConsolePlayer.h"
#include "../include/AIPlayer.h"
#include "BoardCreator.h"
#include "../include/DefaultGameLogic.h"

/**
 * testing if the console player is a console player.
 */
TEST(test_console_test, player_test) {
    Player* player = new ConsolePlayer(white);
    EXPECT_EQ(player->getPType(), Console);
    delete player;
}

/**
 * testing if an ai player is an ai player.
 **/
TEST(test_AI_test, player_test) {
    Player* player = new AIPlayer(white);
    EXPECT_EQ(player->getPType(), AI);
    delete player;
}

/**
 * testing if the ai player does the right move.
 **/
TEST(test_AIboard1_test, player_test) {
    Player* player = new AIPlayer(white);
    BoardCreator* creator;
    Board* board = creator->board1();
    //board->print();
    GameLogic* logic = new DefaultGameLogic(player);
    logic->setTurn(white);
    vector<Location> moves = logic->getPossibleMoves(board->getTable(), 8);
    player->performMove(moves, board, logic);
    EXPECT_EQ(board->getTable()[7][1].getStatus(), 2);
    EXPECT_EQ(board->getTable()[6][2].getStatus(), 2);
    EXPECT_EQ(board->getTable()[5][3].getStatus(), 2);
    //delete creator;
    delete player;
    delete board;
    delete logic;
    moves.clear();
    //delete moves;
}
