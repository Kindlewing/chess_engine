#include <stdlib.h>
#include "chess.h"

int main(void) {
    board board = {0};

    string *starting_fen = string_create_from_cstring(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false);

    board.all_pieces = 0;
    board.all_pieces = board.all_pieces | (1 << g3);

    bb_print(board.all_pieces);
    string_destroy(starting_fen);
    return 0;
}
