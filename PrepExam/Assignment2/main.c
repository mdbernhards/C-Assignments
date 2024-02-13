#include <stdio.h>
#include <string.h>
#include "functions.h"

int NumberOfOccurrences = 0;

void remove_characters(char* str, int numberOfChars){
    char array[100] = {' '};
    strcpy(array, str);

    for (int i = 0; i < (int)strlen(array); ++i) {
        array[i] = array[i+numberOfChars];
    }

    strcpy(str, array);
}

const char* remove_strings(const char* str1, const char* str2){
    char* pointer;

    do {
        pointer = strstr(str1, str2);

        if (pointer != NULL) {
            NumberOfOccurrences++;
            remove_characters(pointer, (int)strlen(str2));
        }

    } while (pointer != NULL);

    return str1;
}

int main(void)
{
    char str1[100], str2[100];
    strcpy(str1, read_string("Enter string 1: "));
    strcpy(str2, read_string("Enter string 2: "));

    const char *result = remove_strings(str1, str2);

    printf("Number of occurrences removed: %d \n", NumberOfOccurrences);
    printf("Resulting string: %s \n", result);
}
