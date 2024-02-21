/*Write a program to find the position of the character 'C' in the sentence
"idea without execution is worthless" 
using pointer and string.*/
#include <stdio.h>

int findCharPosition(const char *sentence, char target) {
    const char *ptr = sentence;
    int position = 0;

    while (*ptr != '\0') {
        if (*ptr == target || *ptr == target + 32) {  // In ASCII, the uppercase and lowercase letters have a
                                                        // difference of 32 in their ASCII values
            return position + 1;  // Adding 1 to make the position 1-based
        }
        position++;
        ptr++;
    }

    return -1;  // Character not found
}

int main() {
    const char *sentence = "idea without execution is worthless";
    char targetChar = 'C';

    int position = findCharPosition(sentence, targetChar);

    if (position != -1) {
        printf("The position of '%c' in the sentence is: %d\n", targetChar, position);
    } else {
        printf("'%c' not found in the sentence.\n", targetChar);
    }

    return 0;
}
 