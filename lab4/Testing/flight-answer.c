#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOTE: In this file, you will encounter a few standard library functions you may not have seen
 * yet, like strcpy and strcmp. We encourage you to read the documentation for these functions
 * to understand what they do. For example, to pull up the documentation for `strcpy`, run:
 *
 * $ man strcpy
 *
 * Good luck!
 */

struct airport {
    char name[4];
    struct airport *next;
};

// There are no bugs in this function as far as we know.
struct airport *create_from_array(const char **array, int length) {
    struct airport *first = NULL;

    for (int i = length - 1; i >= 0; --i) {
        struct airport *new = malloc(sizeof(struct airport));
        strncpy(new->name, array[i], 4);
        new->next = first;
        first = new;
    }

    return first;
}

void bad_free_path_1(struct airport *path) {
    struct airport *ptr = path;
    while (ptr != NULL) {
        struct airport *next = ptr->next;  //get next pointer
        free(ptr);
        ptr = next;
    }
}

int bad_remove_element(struct airport **path, char *name) { //removed ptr->next instead of ptr, needs to remove head, free removed node
    struct airport *curr = *path;
    struct airport *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
          
            if (prev == NULL) {
                *path = curr->next;
            } else {
                prev->next = curr->next;
            }

            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }

    return 0;
}

int bad_insert_element_at_pos(struct airport **path, char *name, int pos) {  //strcopy overflow, fix 0 logic, traverse better
    struct airport *new_airport = malloc(sizeof(struct airport));
    strncpy(new_airport->name, name, 3);
    new_airport->name[3] = '\0';  
    if (pos == 0) {
        new_airport->next = *path;
        *path = new_airport;
        return 1;
    }

    struct airport *curr = *path;
    int i = 0;

    while (curr != NULL && i < pos - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        free(new_airport);
        return 0;
    }

    new_airport->next = curr->next;
    curr->next = new_airport;
    return 1;
}

void print_list(struct airport *curr) {
    if (curr && curr->next) {
        printf("This airport is %s, and the next airport is %s\n", curr->name, curr->next->name);
    } else if (curr) {
        printf("This airport is %s, and it is the last airport\n", curr->name);
    }
    if (curr) {
        print_list(curr->next);
    }
}

/* Write your tests below!
 *
 * As explained in the lab instructions, "assert" checks if the argument is true (nonzero).
 * If the argument is true, the function returns, and nothing special happens.
 * If the argument is false, the function prints an "Assertion failed" error and stops the program.
 * We use "assert" function calls to verify the outcome of a functionality being tested.
 *   By the way, not all tests need to have an assert function call.
 * Use our example for inspiration, and write a few more tests to expose more bugs!
 */

void test_free_path_1() {
    const char *path_array[] = {"SAN", "LAS", "DTW"};
    struct airport *path = create_from_array(path_array, 3);

    print_list(path);
    assert(strcmp(path->name, "SAN") == 0);

    bad_free_path_1(path);
}

int main(void) {
    test_free_path_1();
    // Remember to call your test functions here
}
