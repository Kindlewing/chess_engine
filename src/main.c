#include <stdint.h>
#include <stdio.h>

void print_bitboard(uint64_t board) {
  for (int file = 0; file < 8; file++) {
    for (int rank = 0; rank < 8; rank++) {
      printf(" %lu  ", (board >> (rank * 8 + file)) & 1);
    }
    printf("\n");
  }
}

uint64_t set_bit(uint64_t bitboard, int rank, int file) {
  long bit = 1L << (rank * 8 + file);
  return (bitboard | bit);
}

int main() {
  uint64_t bitboard = 0L;
  print_bitboard(bitboard);

  return 0;
}
