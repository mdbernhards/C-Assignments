#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

const int ARRAY_LENGTH = 100;

/// Removes all whitespace and punctuation from the given string.
/// @param string the string to remove whitespace and punctuation from
void remove_whitespace(char *string)
{
    int i, j = 0;

    for (i = 0; i < (int)strlen(string); i++)
    {
        if (!isspace(string[i]) && !ispunct(string[i]))
        {
            string[j++] = string[i];
        }
    }

    string[j] = '\0';
}

int main(void)
{
    char input[ARRAY_LENGTH];

    strcpy(input, read_string("Enter a line of text: "));

    remove_whitespace(input);

    printf("Modified string: %s", input);

    return 0;
}
