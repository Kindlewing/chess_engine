#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "typedefs.h"
#include "string.h"

typedef u64 bitboard;

typedef enum {
    NONE,
    WHITE_KINGSIDE,
    WHITE_QUEENSIDE,
    BLACK_KINGSIDE,
    BLACK_QUEENSIDE
} castling_rights;

typedef enum { WHITE, BLACK } side_to_move;

typedef struct {
    bitboard white_pawns;
    bitboard white_knights;
    bitboard white_bishops;
    bitboard white_rooks;
    bitboard white_queens;
    bitboard white_king;

    bitboard black_pawns;
    bitboard black_knights;
    bitboard black_bishops;
    bitboard black_rooks;
    bitboard black_queens;
    bitboard black_king;

    bitboard all_white_pieces;
    bitboard all_black_pieces;
    bitboard all_pieces;

    castling_rights castle_rights;

} board;

/* clang-format off */
typedef enum {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
} square;
/* clang-format on */

void board_generate_from_fen(board *board, string *fen);
void bitboard_print(bitboard bb);
