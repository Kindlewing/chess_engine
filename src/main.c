#include <stdio.h>
#include "chess.h"

int main(void) {
    string *fen = string_create_from_cstring(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false);

    bitboard starting_board = bb_generate_from_fen(fen);
    bb_print(starting_board);
    string_destroy(fen);
    return 0;
}
