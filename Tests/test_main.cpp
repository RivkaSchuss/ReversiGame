//
// Created by Rivka Schuss on 26/11/2017.
//

#include <gtest/gtest.h>
#include "../Board.h"



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
 TEST(board__Test, board__Test_bo_Test) {
    Board board(8);
    EXPECT_EQ(8, board.getSize());
}