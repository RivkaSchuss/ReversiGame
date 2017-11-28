//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../Board.h"
#include "../DefaultGameLogic.h"
#include "../ConsolePlayer.h"
#include "BoardCreator.h"


TEST(logic_possibleMoves_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    Location* firstMove = logic->getPossibleMoves(board.getTable(), 8);
    EXPECT_EQ(firstMove->getRow(), 6);
    EXPECT_EQ(firstMove->getCol(), 5);
    delete secondPlayer;
    delete logic;
    delete firstMove;
}

TEST(logic_clearMoveArea_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    Location* firstMove = logic->clearMoveArea(board.getTable(), 8, 4, 5, 0);
    EXPECT_EQ(firstMove->getRow(), 6);
    EXPECT_EQ(firstMove->getCol(), 5);
    delete secondPlayer;
    delete logic;
    delete firstMove;
}

TEST(logic_notFirstTurn_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    EXPECT_EQ(logic->getNotFirstTurn(), 0);
    delete secondPlayer;
    delete logic;
}

TEST(logic_deadLocation_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board* board = new Board(8);
    Location* firstMove = logic->removeOneDead(up, 4, 3, board);
    EXPECT_EQ(firstMove->getRow(), 3);
    EXPECT_EQ(firstMove->getCol(), 3);
    delete secondPlayer;
    delete logic;
    delete board;
}

TEST(logic_place_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    EXPECT_EQ(logic->whichPlace(0, -2), east);
    delete secondPlayer;
    delete logic;
}

TEST(logic_moveExist_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    Location* firstMove = logic->getPossibleMoves(board.getTable(), 8);
    Location checkLocation(6,5);
    EXPECT_EQ(logic->moveExist(firstMove, checkLocation, 0), true);
    delete secondPlayer;
    delete logic;
}

TEST(test_possMovesBoard2_test, logic_test) {
    Player* player = new ConsolePlayer(white);
    BoardCreator* creator;
    Board* board = creator->board2();
    //board->print();
    GameLogic* logic = new DefaultGameLogic(player);
    Location* moves = logic->getPossibleMoves(board->getTable(), 8);
    EXPECT_EQ(moves->getRow(), 7);
    EXPECT_EQ(moves->getCol(), 7);
    delete player;
    delete board;
    delete logic;
    delete moves;
}

/*
TEST(test_flipCellBoard2_test, logic_test) {
    Player* player = new ConsolePlayer(white);
    BoardCreator* creator;
    Board* board = creator->board2();
    board->print();
    GameLogic* logic = new DefaultGameLogic(player);
    //logic->setTurn(black);
    logic->flipDeadCell(8, 5, board);
    board->print();
    EXPECT_EQ(board->getTable()[5][5].getStatus(), 1);
    //EXPECT_EQ(board->getTable()[6][5].getStatus(), 1);
    //EXPECT_EQ(board->getTable()[7][5].getStatus(), 1);
    EXPECT_EQ(board->getTable()[8][5].getStatus(), 1);
    delete player;
    delete board;
    delete logic;
}
 */

