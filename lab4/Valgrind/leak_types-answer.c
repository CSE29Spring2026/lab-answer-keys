#include <stdlib.h>
#include <stdio.h>

void definitely_lost() {
    int* p = malloc(sizeof(int));
    free(p);
}

void indirectly_lost() {
    int** pp = malloc(sizeof(int*));
    *pp = malloc(sizeof(int));
    free(*pp);
    free(pp);
}

int* array;
void possibly_lost() {
    array = malloc(sizeof(int) * 5);
    int* temp = array;
    array += 2;
    free(temp);
    free(array);
    
}

int* global_p;
void still_reachable() {
    global_p = malloc(sizeof(int));
    free(global_p);
    global_p = NULL;
}

int main() {
    definitely_lost();
    indirectly_lost();
    possibly_lost();
    still_reachable();
    return 0;
}
