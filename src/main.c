#include <string.h>
#include <unistd.h>

int main(void) {
    string *fen = string_create_from_cstring(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false);

    string_destroy(fen);
    return 0;
}
