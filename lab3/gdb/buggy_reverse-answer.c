#include <stdio.h>
#include <string.h>

// Swaps 2 chars in a string. 
// Returns 1 if they needed to swap, 0 if they were already matching
int swap (char str[], int first, int second) {
    if (str[first] == str[second]) {         //change to ==
        return 0;
    }

    char temp = str[first];
    str[first] = str[second];
    str[second] = temp;
    return 1;
}

// Reverses the given string in-place, and returns number of chars swapped. 
int reverse(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;
    int num_swaps = 0;

    // Stop when i and j meet in the middle
    while (i < j) { //change to <
        num_swaps += swap(str, i, j);
        i++;
        j--;
    } 
    return num_swaps //add a return
}

int main(int argc, char *argv[]) {

    char str0[] = "Racecar";
    int swaps0 = reverse(str0);
    printf("Reversed: \"%s\", num swaps: %d\n", str0, swaps0);

    char str1[] = "Joe G. Politz";
    int swaps1 = reverse(str1);
    printf("Reversed: \"%s\", num swaps: %d\n", str1, swaps1);

    char str2[] = "Aaron Schulman";
    int swaps2 = reverse(str2);
    printf("Reversed: \"%s\", num swaps: %d\n", str2, swaps2);
    
	char str3[] = "Gerald A. Soosairaj";
    int swaps3 = reverse(str3);
    printf("Reversed: \"%s\", num swaps: %d\n", str3, swaps3);
	
	char str4[] = "Olivia Weng";
    int swaps4 = reverse(str4);
    printf("Reversed: \"%s\", num swaps: %d\n", str4, swaps4);
    return 0;
}
