#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint64_t bitboard;

typedef enum {
	None = 0,
	Pawn = 1,
	Rook = 2,
	Knight = 3,
	Bishop = 4,
	Queen = 5,
	King = 6,
	Black = 8,
	White = 16
} piece;

// clang-format off
// squares
typedef enum {
	a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
} square;
// clang-format on

int *to_binary(uint64_t decimal) {
	int *binary = (int *)malloc(sizeof(int) * 64);
	if (binary == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	for (int i = 0; i < 64; i++) {
		binary[i] = decimal & 1;
		decimal >>= 1L;
	}
	return binary;
}

void print_binary(int *binary) {
	for (int i = 64; i > 0; i--) {
		printf("%d", binary[i]);
	}
	printf("\n");
}

void set_bit(bitboard *bitboard, square square) {
	*bitboard |= (1L << square);
}

int get_bit(bitboard bitboard, square square) {
	long mask = 1L << square;
	printf("%ldl\n", mask);
	return (mask & bitboard) != 0;
}

bitboard pop_bit(bitboard bitboard, square square) {
	return get_bit(bitboard, square) ? bitboard ^= (1L << square) : 0;
}

void print_bitboard(bitboard bitboard) {
	printf("\n");

	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			int square = rank * 8 + file;
			if (!file) {
				printf("  %d ", 8 - rank);
			}
			printf(" %d", get_bit(bitboard, square) ? 1 : 0);
		}
		printf("\n");
	}
	printf("\n     a b c d e f g h\n\n");
	printf("     Bitboard: %lud\n\n", bitboard);
}

int main() {
	bitboard board = 0L;
	return 0;
}
