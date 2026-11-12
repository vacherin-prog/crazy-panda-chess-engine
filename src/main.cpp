#include "board.h"
#include "types.h"
#include <iostream>
int main() {
  std::cout << "Hello World!\n";
  Board game_board;
  game_board.load_fen(DEFAULT_FEN);
}
