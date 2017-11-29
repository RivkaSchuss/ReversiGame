//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../include/Board.h"

/**
 * checks if the board size is correct.
 */
TEST(board__Test, board_Test) {
    Board board(8);
    EXPECT_EQ(8, board.getSize());
}


