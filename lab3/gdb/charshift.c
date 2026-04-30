#include <stdio.h>
#define CHARSHIFT 4

void shift_chars(char *str, int amount) {
    for (char *ch = str; *ch != 0; ++ch) { //fix the ch into *ch
        if (*ch >= 'A' && *ch <= 'Z') {
            *ch = (*ch - 'A' + amount) % 26 + 'A';
        } else if (*ch >= 'a' && *ch <= 'z') {
            *ch = (*ch - 'a' + amount) % 26 + 'a';
        }
    }
}

int main(void) {
    char message[] = "Whpdkqcd ukq ywj wrkez zaxqccejc wjz fqop snepa lanbayp ykza pdwp skngo kj ukqn benop pnu, pdeo eo jaran pda ywoa bkn ykilhat lnkcnwio!";

    shift_chars(message, CHARSHIFT);
    puts(message);
}
