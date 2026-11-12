#include "board.h"
#include "types.h"
#include <exception>
#include <iostream>
#include <stdexcept>
int main() {
  std::string input =
      "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R b KQkq - 3 3";
  Board game_board;
  try {
    game_board.load_fen(input);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 0;
  }
  game_board.print();
}
