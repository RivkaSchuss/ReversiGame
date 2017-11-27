//
// Created by Rivka Schuss on 26/11/2017.
//

#include <gtest/gtest.h>
#include "../Board.h"
#include "../DefaultGameLogic.h"
#include "../ConsolePlayer.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

TEST(board__Test, board_Test) {
    Board board(8);
    EXPECT_EQ(8, board.getSize());
}

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
