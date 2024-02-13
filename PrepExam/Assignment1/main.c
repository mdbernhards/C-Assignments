#include <stdio.h>
#include <ctype.h>
#include "functions.h"

int main(void)
{
    char array[10], upperChars[20] = {' '},  lowerChars[20] = {' '};
    int lowerCount = 0, upperCount = 0;

    for (int i = 0; i < 10; ++i) {
        char charEntered = read_char("Enter a character ($ to stop):");
        if (charEntered == '$') {
            break;
        }
        else {
            array[i] = charEntered;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (isupper(array[i])) {
            if (upperCount != 0) {
                upperChars[upperCount] = ',';
                upperCount++;
            }
            upperChars[upperCount] = array[i];
            upperCount++;
        }
        else if (islower(array[i])) {
            if (lowerCount != 0) {
                lowerChars[lowerCount] = ',';
                lowerCount++;
            }
            lowerChars[lowerCount] = array[i];
            lowerCount++;
        }
    }

    printf("Uppercase characters: %s \n", upperChars);
    printf("Lowercase characters: %s \n", lowerChars);
}
setbuf(stdout, NULL);