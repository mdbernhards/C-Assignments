#include <stdio.h>
#include <string.h>
#include "functions.h"

const int ARRAY_LENGTH = 100;

/// Swaps the two strings if the first string is alphabetically larger than the second string.
/// @param a The memory address of the first string.
/// @param b The memory address of the second string.
void sort_two_strings(const char **a, const char **b)
{
    if (strcmp(*a, *b) > 0)
    {
        char temp[ARRAY_LENGTH];
        strncpy(temp, *a, ARRAY_LENGTH);
        strncpy((char *)*a, *b, ARRAY_LENGTH);
        strncpy((char *)*b, temp, ARRAY_LENGTH);
    }
}

int main(void)
{
    const int MAX_LENGTH = 100;
    char string1[MAX_LENGTH], string2[MAX_LENGTH], string3[MAX_LENGTH];

    printf("Please enter three strings:\n");
    strcpy(string1,read_string(""));
    strcpy(string2,read_string(""));
    strcpy(string3,read_string(""));

    const char *pointer1 = string1;
    const char *pointer2 = string2;
    const char *pointer3 = string3;

    sort_two_strings(&pointer1, &pointer2);
    sort_two_strings(&pointer2, &pointer3);
    sort_two_strings(&pointer1, &pointer2);

    printf("The strings in alphabetical order are: %s, %s, %s\n", pointer1, pointer2, pointer3);

    return 0;
}
