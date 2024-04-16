#include <stdint.h>
#include <stdio.h>

uint64_t set_bit(uint64_t bitboard, int rank, int file) {
	uint64_t bit = 1L;
	return bitboard |= (bit << (rank * 8 + file));
}

int main() {
	uint64_t bitboard = 0L;

	for(int file = 0; file < 8; file++) {
		for(int rank = 0; rank < 8; rank++) {
			printf(" %lu ", bitboard);
		}
		printf("\n");
	}

	printf("\n\n");
	uint64_t new_board = set_bit(bitboard, 4, 4);

	for(int file = 0; file < 8; file++) {
		for(int rank = 0; rank < 8; rank++) {
			printf(" %lu ", new_board);
		}
		printf("\n");
	}
	return 0;
}


