#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitboard.h"

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

int main() {
	bitboard board = 0L;
	print_bitboard(board);
	return 0;
}
