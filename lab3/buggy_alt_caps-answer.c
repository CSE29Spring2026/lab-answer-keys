#include <stdio.h>
#include <string.h>


// If char is a-z, returns uppercase version.
// Otherwise, returns it unchanged
char capitalize_char(char ch) {
    if ('a' <= ch && ch <= 'z') { //fix this to &&
        ch -= 32;  // uppercase and lowercase ascii is 32 apart
    }
    return ch;
}


// Takes a string, uppercases every other character
// e.g. "hello world" -> "HeLlO WoRlD"
void alternate_caps(char str[]) {
    int len = strlen(str);

    for(int i = 0; i != len; i += 2) {
        str[i] = capitalize_char(str[i]);
    }
}

int main() {
    char string1[] = "I can score 100 on the test!";
    char string2[] = "eat your fruits and vegetables!";
    
    alternate_caps(string1);
    printf("%s\n", string1);

    alternate_caps(string2);
    printf("%s\n", string2);
}
