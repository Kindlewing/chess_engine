#include "chess.h"

int main(void) {
    board board = {0};
    string *starting_fen = string_create_from_cstring(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false);
    board_generate_from_fen(&board, starting_fen);
    bitboard_print(board.all_pieces);

    string_destroy(starting_fen);
    return 0;
}
