#pragma once
#include "types.h"
#include <string>

struct Board {
  int squares[64] = {EMPTY};
  int side_to_move = WHITE;
  int castle_rights = ALL_CASTLE;
  int en_passant_square = -1;
  int half_move_clock = 0;
  int full_move_number = 0;

  void print() const;
  void load_fen(const std::string &fen);

  static Piece char_to_piece(char c) {
    switch (c) {
    case 'P':
      return W_PAWN;
    case 'N':
      return W_KNIGHT;
    case 'B':
      return W_BISHOP;
    case 'R':
      return W_ROOK;
    case 'Q':
      return W_QUEEN;
    case 'K':
      return W_KING;
    case 'p':
      return B_PAWN;
    case 'n':
      return B_KNIGHT;
    case 'b':
      return B_BISHOP;
    case 'r':
      return B_ROOK;
    case 'q':
      return B_QUEEN;
    case 'k':
      return B_KING;
    default:
      return EMPTY;
    }
  }

  static char piece_to_char(Piece p) {
    switch (p) {
    case W_PAWN:
      return 'P';
    case W_KNIGHT:
      return 'N';
    case W_BISHOP:
      return 'B';
    case W_ROOK:
      return 'R';
    case W_QUEEN:
      return 'Q';
    case W_KING:
      return 'K';
    case B_PAWN:
      return 'p';
    case B_KNIGHT:
      return 'n';
    case B_BISHOP:
      return 'b';
    case B_ROOK:
      return 'r';
    case B_QUEEN:
      return 'q';
    case B_KING:
      return 'k';
    default:
      return '.';
    }
  };

  static int char_to_rank(char c) {
    switch (c) {
    case 'a':
      return 0;
    case 'b':
      return 1;
    case 'c':
      return 2;
    case 'd':
      return 3;
    case 'e':
      return 4;
    case 'f':
      return 5;
    case 'g':
      return 6;
    case 'h':
      return 7;
    default:
      return 0;
    }
  }

  static int get_index(int rank, int file) { return rank * 8 + file; };
  static int get_rank(int index) { return index / 8; };
  static int get_file(int index) { return index % 8; };
};
