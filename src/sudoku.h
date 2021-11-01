#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// define a function to print the board
void print_board(vector<vector<int>> &b)
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}

// define is_valid function
bool is_valid(vector<vector<int>> &b, int i, int j, int k)
{
  // check row
  for (int m = 0; m < 9; m++)
  {
    if (b[i][m] == k)
    {
      return false;
    }
  }
  // check column
  for (int m = 0; m < 9; m++)
  {
    if (b[m][j] == k)
    {
      return false;
    }
  }
  // check 3x3 block
  int x = i / 3 * 3, y = j / 3 * 3;
  for (int m = 0; m < 3; m++)
  {
    for (int n = 0; n < 3; n++)
    {
      if (b[x + m][y + n] == k)
      {
        return false;
      }
    }
  }
  return true;
}

// solve the sudoku
bool solve(vector<vector<int>> &b)
{
  // find the first empty cell
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (b[i][j] == 0)
      {
        for (int k = 1; k <= 9; k++)
        {
          if (is_valid(b, i, j, k))
          {
            b[i][j] = k;
            if (solve(b))
            {
              return true;
            }
            b[i][j] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

// define a function to check if the board is valid
bool check_board(vector<vector<int>> &b)
{
  // check rows
  for (int i = 0; i < 9; i++)
  {
    vector<int> row(10, 0);
    for (int j = 0; j < 9; j++)
    {
      row[b[i][j]]++;
    }
    for (int j = 1; j < 10; j++)
    {
      if (row[j] > 1)
      {
        return false;
      }
    }
  }
  // check columns
  for (int i = 0; i < 9; i++)
  {
    vector<int> col(10, 0);
    for (int j = 0; j < 9; j++)
    {
      col[b[j][i]]++;
    }
    for (int j = 1; j < 10; j++)
    {
      if (col[j] > 1)
      {
        return false;
      }
    }
  }
  // check 3x3 blocks
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      vector<int> block(10, 0);
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          block[b[i + k][j + l]]++;
        }
      }
      for (int k = 1; k < 10; k++)
      {
        if (block[k] > 1)
        {
          return false;
        }
      }
    }
  }
  return true;
}

// define a function to generate a random number between 1 and 9
int rand_num()
{
  srand((unsigned int)time(NULL) + rand() % 3);
  return rand() % 9 + 1;
}

// define a position in the board randomly
std::tuple<int, int> rand_pos(vector<vector<int>> &b)
{
  int x = rand_num();
  int y = rand_num();
  while (b[x][y] != 0)
  {
    x = rand_num();
    y = rand_num();
  }
  return make_tuple(x, y);
}

bool seed_board(vector<vector<int>> &b, int out_i, int out_j)
{
  for (int i = out_i; i < 9 + 1; i++)
  {
    for (int j = out_j; j < 9; j++)
    {
      if (b[i][j] == 0)
      {
        for (int k = 1; k <= 9; k++)
        {
          if (is_valid(b, i, j, k))
          {
            b[i][j] = k;
            if (solve(b))
            {
              return true;
            }
            b[i][j] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

vector<vector<int>> generate_sudoku()
{
  vector<vector<int>> b(9, vector<int>(9, 0));
  auto pos = rand_pos(b);
  int x = get<0>(pos);
  int y = get<1>(pos);
  b[x][y] = rand_num();
  seed_board(b, x, y);
  return std::move(b);
}

#endif