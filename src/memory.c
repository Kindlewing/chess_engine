#include "memory.h"
#include <assert.h>

arena arena_create(size_t capacity) {
    void *data = malloc(sizeof(uint8_t) * capacity);
    arena a = {
        .data = data,
        .capacity = capacity,
        .size = 0,
        .offset = 0,
    };
    return a;
}

void *arena_alloc(arena *arena, size_t alloc_size) {
    assert(alloc_size + arena->size < arena->capacity);
    void *data = &arena->data[arena->size];
    arena->size += alloc_size;
    return data;
}

void arena_free(arena *arena) {
    arena->capacity = 0;
    arena->size = 0;
    free(arena->data);
}
