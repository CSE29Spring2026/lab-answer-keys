#include <stdio.h>
#include <string.h>

// count vowels in a string (case-insensitive)
int count_vowels(char str[]) {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
		    || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count = count + 1; //fix to count+1
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int vowels = count_vowels(argv[1]);

    printf("Number of vowels: %d\n", vowels);
    return 0;
}
