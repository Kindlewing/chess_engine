#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    size_t size;
    size_t offset;
    size_t capacity;
} arena;

arena arena_create(size_t capacity);
void *arena_alloc(arena *arena, size_t alloc_size);
void arena_free(arena *arena);
