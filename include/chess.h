#ifndef CHESS_H
#define CHESS_H

#include <stdint.h>

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

#endif // CHESS_H
