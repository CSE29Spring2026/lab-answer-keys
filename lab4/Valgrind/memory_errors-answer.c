#include <stdlib.h>

void memory_leak() {
    int* p = malloc(sizeof(int));
    free(p);
}

void free_after_set() {
    int* p = malloc(sizeof(int));
    free(p);
    p = NULL;
}

void double_free() {
    int* p = malloc(sizeof(int));
    free(p);
    p = NULL;
}

void set_int(int* p) {
    if (p != NULL) {
        *p = 42;
    }
}

void reuse_freed() {
    int* p = malloc(sizeof(int));
    set_int(p);
    free(p);
    p = NULL;
    set_int(p);
}

void double_malloc() {
    int* p = malloc(sizeof(int));
    free(p);
    p = malloc(sizeof(int));
    free(p);
}

int main() {
    memory_leak();
    free_after_set();
    double_free();
    reuse_freed();
    double_malloc();
    return 0;
}
