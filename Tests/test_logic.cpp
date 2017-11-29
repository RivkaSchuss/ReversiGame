//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../include/Board.h"
#include "../include/DefaultGameLogic.h"
#include "../include/ConsolePlayer.h"
#include "BoardCreator.h"

/**
 * checking if the possible moves are correct.
 **/
TEST(logic_possibleMoves_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    vector<Location> moves = logic->getPossibleMoves(board.getTable(), 8);
    EXPECT_EQ(moves[0].getRow(), 6);
    EXPECT_EQ(moves[0].getCol(), 5);
    delete secondPlayer;
    delete logic;
    moves.clear();
}

/**
 * checking if the function clearMoveArea returns the proper list.
 **/
TEST(logic_clearMoveArea_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    vector<Location> moves = logic->clearMoveArea(board.getTable(), 8, 4, 5, 0);
    EXPECT_EQ(moves[0].getRow(), 6);
    EXPECT_EQ(moves[0].getCol(), 5);
    delete secondPlayer;
    delete logic;
    moves.clear();
}

/**
 * checking if the first turn booleanis correct.
 **/
TEST(logic_notFirstTurn_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    EXPECT_EQ(logic->getNotFirstTurn(), 0);
    delete secondPlayer;
    delete logic;
}

/**
 * checking if the function works properly.
 **/
TEST(logic_deadLocation_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board* board = new Board(8);
    Location* move = logic->removeOneDead(up, 4, 3, board);
    EXPECT_EQ(move->getRow(), 3);
    EXPECT_EQ(move->getCol(), 3);
    delete secondPlayer;
    delete logic;
    delete board;
    delete move;

}

/**
 * checking if the place is correct for a given row and column.
 **/
TEST(logic_place_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    EXPECT_EQ(logic->whichPlace(0, -2), east);
    delete secondPlayer;
    delete logic;
}

/**
 * checking if the move exist function works for a move that exists.
 **/
TEST(logic_moveExist_Test, logic_test) {
    Player *secondPlayer  =  new ConsolePlayer(white);
    GameLogic* logic = new DefaultGameLogic(secondPlayer);
    Board board(8);
    vector<Location> moves = logic->getPossibleMoves(board.getTable(), 8);
    Location checkLocation(6,5);
    EXPECT_EQ(logic->moveExist(moves, checkLocation), true);
    delete secondPlayer;
    delete logic;
    moves.clear();
}

/**
 * checking if the possible moves are correct for a different board given.
 **/
TEST(test_possMovesBoard2_test, logic_test) {
    Player* player = new ConsolePlayer(white);
    BoardCreator* creator;
    Board* board = creator->board2();
    //board->print();
    GameLogic* logic = new DefaultGameLogic(player);
    vector<Location> moves = logic->getPossibleMoves(board->getTable(), 8);
    EXPECT_EQ(moves[0].getRow(), 7);
    EXPECT_EQ(moves[0].getCol(), 7);
    delete player;
    delete board;
    delete logic;
    moves.clear();
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

