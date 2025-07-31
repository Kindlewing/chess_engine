#include "chess.h"
#include <stdio.h>
#include <unistd.h>

bitboard bb_generate_from_fen(string *fen) {
    bitboard bitboard = 0;

    for (size_t i = 0; i < fen->length; i += 1) {
        printf("%c", fen->data[i]);
    }
    printf("\n");
    return bitboard;
}

void bb_print(bitboard bb) {
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
