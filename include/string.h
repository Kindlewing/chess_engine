#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} string;

string *string_create_from_cstring(const char *str, bool null_t);
void string_destroy(string *str);
