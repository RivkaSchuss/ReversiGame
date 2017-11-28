//
// Created by Rivka Schuss on 28/11/2017.
//

#include <gtest/gtest.h>
#include "../Board.h"

TEST(cell_emptiness_Test, cell_Test) {
    Board board(8);
    int i;
    for (i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getTable()[i][j].getStatus() == 0) {
                EXPECT_EQ(board.getTable()[i][j].getStatus(), 0);
            }
        }
    }
}