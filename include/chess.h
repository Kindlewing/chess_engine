#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "string.h"

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;
typedef u64 bitboard;

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

bitboard bb_generate_from_fen(string *fen);
void bb_print(bitboard bb);
