#include "bitboard.h"
#include <stdio.h>

void set_bit(bitboard *bitboard, square square) {
	*bitboard |= (1L << square);
}

int get_bit(bitboard bitboard, square square) {
	long mask = 1L << square;
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
				printf("  %d |", 8 - rank);
			}
			printf(" %d", get_bit(bitboard, square) ? 1 : 0);
		}
		printf("\n");
	}
	printf("      - - - - - - - - \n");
	printf("      a b c d e f g h\n\n");
	printf(" Bitboard: %lud\n\n", bitboard);
}
