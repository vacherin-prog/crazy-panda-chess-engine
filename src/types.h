#pragma once

#include <string>

const std::string DEFAULT_FEN =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

enum Color { WHITE = 1, BLACK = -1 };

enum Piece {
  EMPTY = 0,
  W_PAWN = 1,
  W_KNIGHT = 2,
  W_BISHOP = 3,
  W_ROOK = 4,
  W_QUEEN = 5,
  W_KING = 6,
  B_PAWN = -1,
  B_KNIGHT = -2,
  B_BISHOP = -3,
  B_ROOK = -4,
  B_QUEEN = -5,
  B_KING = -6
};

enum Castling {
  NO_CASTLE = 0b0000,
  ALL_CASTLE = 0b1111,
  WHITE_CASTLE = 0b0011,
  WK_CASTLE = 0b0001,
  WQ_CASTLE = 0b0010,
  BLACK_CASTLE = 0b1100,
  BK_CASTLE = 0b0100,
  BQ_CASTLE = 0b1000
};
