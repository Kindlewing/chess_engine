#include "string.h"
#include <assert.h>
#include <stdlib.h>

string *string_create_from_cstring(const char *str, bool null_t) {
    assert(str != NULL);
    size_t len = 0;
    while (str[len] != '\0') {
        len += 1;
    }
    string *s = malloc(sizeof(string));
    assert(s != NULL);
    if (null_t) {
        s->data = malloc(len + 1);
    } else {
        s->data = malloc(len);
    }
    assert(s->data != NULL);
    for (size_t i = 0; i < len; ++i) {
        s->data[i] = str[i];
    }

    if (null_t) {
        s->data[len] = '\0';
        s->capacity = len + 1;
    } else {
        s->capacity = len;
    }

    s->length = len;
    return s;
}

void string_destroy(string *str) {
    if (str) {
        free(str->data);
        free(str);
    }
}
