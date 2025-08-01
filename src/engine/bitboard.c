#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "chess.h"

void board_generate_from_fen(board *board, string *fen) {
    assert((fen != NULL) && "fen string must not be null");
    u32 curr = 0;
    u32 rank = 7;
    u32 file = 0;

    while (fen->data[curr] != ' ') {
        square sq = (square)(rank * 8 + file);
        char c = fen->data[curr];

        switch (c) {
        case '/':
            rank -= 1;
            file = 0;
            break;
        case '1': file += 1; break;
        case '2': file += 2; break;
        case '3': file += 3; break;
        case '4': file += 4; break;
        case '5': file += 5; break;
        case '6': file += 6; break;
        case '7': file += 7; break;
        case '8': file += 8; break;
        case 'r':
            board->black_rooks |= 1ULL << sq;
            file += 1;
            break;
        case 'n':
            board->black_knights |= 1ULL << sq;
            file += 1;
            break;
        case 'p':
            board->black_pawns |= 1ULL << sq;
            file += 1;
            break;
        case 'b':
            board->black_bishops |= 1ULL << sq;
            file += 1;
            break;
        case 'q':
            board->black_queens |= 1ULL << sq;
            file += 1;
            break;
        case 'k':
            board->black_king |= 1ULL << sq;
            file += 1;
            break;
        case 'R':
            board->white_rooks |= 1ULL << sq;
            file += 1;
            break;
        case 'N':
            board->white_knights |= 1ULL << sq;
            file += 1;
            break;
        case 'P':
            board->white_pawns |= 1ULL << sq;
            file += 1;
            break;
        case 'B':
            board->white_bishops |= 1ULL << sq;
            file += 1;
            break;
        case 'Q':
            board->white_queens |= 1ULL << sq;
            file += 1;
            break;
        case 'K':
            board->white_king |= 1ULL << sq;
            file += 1;
            break;
        default:
            fprintf(stderr, "Invalid FEN string. Got %c\n", c);
            exit(EXIT_FAILURE);
        }
        curr += 1;
    }

    board->all_black_pieces = board->black_rooks | board->black_pawns |
                              board->black_bishops | board->black_knights |
                              board->black_queens | board->black_king;

    board->all_white_pieces = board->white_rooks | board->white_pawns |
                              board->white_bishops | board->white_knights |
                              board->white_queens | board->white_king;
    board->all_pieces = board->all_white_pieces | board->all_black_pieces;
}

void bitboard_print(bitboard bb) {
    for (int rank = 7; rank >= 0; rank--) {
        printf("%d  ", rank + 1);
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            printf("%c ", (bb & (1ULL << square)) ? '1' : '.');
        }
        printf("\n");
    }
    printf("\n   a b c d e f g h\n");
}
