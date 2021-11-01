#include "sudoku.h"

using namespace std;

int main(int argc, char* argv[]) {
  print_board(generate_sudoku());

  return 0;
}