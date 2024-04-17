#include <stdint.h>
#include <stdio.h>

typedef uint64_t bitboard;

enum piece {
	None = 0,
	Pawn = 1,
	Rook = 2,
	Knight = 3,
	Bishop = 4,
	Queen = 5,
	King = 6,
	Black = 8,
	White = 16
};

// clang-format off
// squares
enum square {
	a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};
// clang-format on

void print_bitboard(bitboard board) {
	for (int file = 0; file < 8; file++) {
		for (int rank = 0; rank < 8; rank++) {
			printf(" %lu  ", (board >> (rank * 8 + file)) & 1);
		}
		printf("\n");
	}
}

void set_bit(bitboard *bitboard, enum square square) {
	*bitboard |= (1L << square);
}

int get_bit(bitboard bitboard, enum square square) {
	long mask = 1L << square;
	return (mask & bitboard) != 0;
}

int main() {
	bitboard board = 0L;

	set_bit(&board, a8);
	set_bit(&board, e4);
	print_bitboard(board);

	return 0;
}
