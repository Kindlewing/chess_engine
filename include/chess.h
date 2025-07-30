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

typedef struct {
    u64 white_pawns;
    u64 white_knights;
    u64 white_bishops;
    u64 white_rooks;
    u64 white_queens;
    u64 white_king;

    u64 black_pawns;
    u64 black_knights;
    u64 black_bishops;
    u64 black_rooks;
    u64 black_queens;
    u64 black_king;
    bool white_turn;
    i32 castle_rights;
    i32 en_passant_square;
} board_state;

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

u64 bb_generate_from_fen(void);
void bb_print(void);
