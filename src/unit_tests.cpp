#include "gtest/gtest.h"

#include "sudoku.h"

TEST(example, demo)
{
  EXPECT_FALSE(2 == 3);
}

// test print_board
TEST(print_board, print_board)
{
  vector<vector<int>> board = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  print_board(board);
}


// test check_board
TEST(is_valid, check_board)
{
  // a example of a valid sudoku board
vector<vector<int>> example_board = {
    {6, 1, 4, 7, 2, 3, 9, 5, 8},
    {3, 7, 5, 8, 9, 4, 1, 2, 6},
    {8, 9, 2, 1, 6, 5, 4, 3, 7},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {9, 4, 8, 2, 3, 7, 6, 1, 5},
    {5, 6, 7, 9, 1, 8, 2, 4, 3},
    {2, 3, 1, 6, 8, 9, 5, 7, 4},
    {4, 5, 6, 3, 7, 1, 8, 9, 2},
    {7, 8, 9, 5, 4, 2, 3, 6, 1}
  };
  EXPECT_TRUE(check_board(example_board));
}

// test solve_board
TEST(solve_board, solve_board)
{
  vector<vector<int>> example_board = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  EXPECT_TRUE(solve(example_board));
  print_board(example_board);
  EXPECT_TRUE(check_board(example_board));
}

// test generate_board
TEST(generate_board, generate_sudoku)
{
  vector<vector<int>> board = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  vector<vector<int>> generatedBoard= generate_sudoku();
  print_board(generatedBoard);
  EXPECT_TRUE(check_board(generatedBoard));
  EXPECT_EQ(generatedBoard.size(), board.size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}