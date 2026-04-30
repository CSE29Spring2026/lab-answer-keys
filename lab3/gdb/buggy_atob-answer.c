#include <stdio.h>

// edits the string, then returns how many changed
int A_to_B(char str[]) {
    int num_As = 0;
    for (int i=0; str[i] != '\0'; i++) {
        if (str[i] = 'A')
            num_As += 1;
            str[i] = 'B';
    }
}

int main(int argc, char *argv[]) {
    char s1[] = "Aaa Aaa Alack Sheep";
    char s2[] = "CANADA";
    char s3[] = "Your grade is a A+";
    char *strings[] = {s1, s2, s3};
    int num_strings = 3;

    for (int i=0; i < num_strings ; i++) {  //change to <
        int num_As = A_to_B(strings[i]);
        printf("\"%s\": %d 'A'es replaced\n", strings[i], num_As);
    }
}
