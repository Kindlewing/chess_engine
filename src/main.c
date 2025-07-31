#include <stdlib.h>
#include "chess.h"

board *board_create() {
    board *board = malloc(sizeof *board);

    return board;
}

int main(void) {
    string *starting_fen = string_create_from_cstring(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false);

    board->all_pieces = 0;
    board->all_pieces = board->all_pieces | (1ULL << g3);
    bb_print(board->all_pieces);
    string_destroy(starting_fen);
    return 0;
}
