#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XXX: You may need to make LARGE-SCALE CHANGES.
 *       It may even be helpful to consider rewriting getQueries while reusing
 * parts of our code. Please collaborate with your group on this!!
 */
char *getQueries(char *url) {
    char *query = malloc(sizeof(char) * (strlen(url) + 1));

    // make our lowercase string
    for (int i = 0; i < strlen(url); i++) {
        query[i] = tolower(url[i]);
    }
    query[strlen(url)] = '\0';

    // search for ?
    char *ptr = query;
    while (*ptr != '?' && *ptr != 0) {
        ptr++;
    }
   if (*ptr == '?') {
    char *result = strdup(ptr + 1);  
    free(query);                    
    return result;                   
    }
    free(query);                         
    return strdup("");  
}

/*
 * XXX: You MAY need to modify the main function.
 */
int main(int argc, char *argv[]) {
    char s[] = "https://example.com/over/there?Name=Ferret";

    // expect output to be name=ferret
    char *queries = getQueries(s);
    printf("%s\n", queries);
    free(queries);

    return 0;
}
