#include "board.h"
#include "types.h"
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

void Board::load_fen(const std::string &fen) {

  for (size_t i = 0; i < std::size(squares); i++) {
    squares[i] = EMPTY;
  }
  side_to_move = WHITE;
  castle_rights = NO_CASTLE;
  en_passant_square = -1;
  half_move_clock = 0;
  full_move_number = 0;

  std::istringstream iss(fen);
  std::string placement, turn, castling, ep;
  int half_move, full_move;

  if (!(iss >> placement >> turn >> castling >> ep >> half_move >> full_move)) {
    throw std::invalid_argument("Invalid FEN passed");
  }

  int rank = 0;
  int file = 0;
  for (char c : placement) {
    if (c == '/') {
      if (file != 8)
        throw std::invalid_argument("Invalid rank width");
      rank++;
      file = 0;
    } else if (std::isdigit(c)) {
      int empty_squares = c - '0';
      for (int i = 0; i < empty_squares; i++) {
        if (file >= 8)
          throw std::invalid_argument("Rank overflow");
        squares[get_index(rank, file++)] = EMPTY;
      }
    } else {
      if (file >= 8)
        throw std::invalid_argument("Rank overflow");
      squares[get_index(rank, file++)] = char_to_piece(c);
    }
  }
  if (rank != 7 || file != 8)
    throw std::invalid_argument("Incomplete Board in FEN");

  switch (turn[0]) {
  case 'w':
    side_to_move = WHITE;
    break;
  case 'b':
    side_to_move = BLACK;
    break;
  default:
    throw std::invalid_argument("Invalid turn");
  };

  if (castling != "-") {
    for (char c : castling) {
      switch (c) {
      case 'K':
        castle_rights |= WK_CASTLE;
        break;
      case 'Q':
        castle_rights |= WQ_CASTLE;
        break;
      case 'k':
        castle_rights |= BK_CASTLE;
        break;
      case 'q':
        castle_rights |= BQ_CASTLE;
        break;
      default:
        throw std::invalid_argument("Invalid castling rights");
      }
    }
  }

  if (ep != "-") {
    en_passant_square = get_index(char_to_rank(ep[0]), (ep[1] - '0') - 1);
  }
  half_move_clock = half_move;
  full_move_number = full_move;
}
