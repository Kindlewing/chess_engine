#include <stdio.h>
#include <stdlib.h>

int main() {
	int NONE = 0;
	int KING = 1;
	int PAWN = 2;
	int KNIGHT = 3;
	int BISHOP = 4;
	int ROOK = 5;
	int QUEEN = 6;

	int BLACK = 8;
	int WHITE = 16;

	int board[64];

	for (int i = 0; i < 64; i++) {
		if (i < 16) // Place white pieces
			board[i] = WHITE | NONE;
		else if (i >= 48) // Place black pieces
			board[i] = BLACK | NONE;
		else // Empty squares in the middle
			board[i] = NONE;
	}

	for (int i = 0; i < 64; i++) {
		printf("%d", board[i]);
	}

	int count = 0;
	for (int i = 0; i < 64; i++) {
		switch (board[i]) {
		case 16:
			printf("W ");
			break;
		case 8:
			printf("B ");
			break;
		case 0:
			printf(". ");
			break;
		default:
			printf("? ");
			break;
		}
		count++;
		if (count == 8) {
			count = 0;
			printf("\n");
		}
	}

	return EXIT_SUCCESS;
}
