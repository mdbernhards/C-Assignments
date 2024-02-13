#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

const int ARRAY_LENGTH = 1000;

/// Counts the number of occurrences of each character in the given string.
/// @param string the string to count the characters in
/// @param counts an array of 26 integers, where the counts of the characters
///   'a' through 'z' will be stored.
void count_characters(const char *string, int counts[static 26])
{
    memset(counts, 0, sizeof(int) * 26);

    for (int i = 0; i < (int)strlen(string); i++)
    {
        if (isalpha(string[i]))
        {
            int index = tolower(string[i]) - 'a';
            counts[index]++;
        }
    }
}

/// Returns true if the two given strings are anagrams of each other.
/// @param string1 the first string
/// @param string2 the second string
/// @returns true if the two strings are anagrams of each other, false otherwise.
bool are_anagrams(const char *string1, const char *string2)
{
    int counts1[26] = {0};
    int counts2[26] = {0};

    count_characters(string1, counts1);
    count_characters(string2, counts2);

    return memcmp(counts1, counts2, sizeof(int) * 26) == 0;
}

int main(void)
{
    char input1[ARRAY_LENGTH];
    char input2[ARRAY_LENGTH];

    strcpy(input1, read_string("Enter a sentence:"));
    strcpy(input2, read_string("Enter the second sentence:"));

    if (are_anagrams(input1, input2))
    {
        printf("\"%s\" and \"%s\" are anagrams.\n", input1, input2);
    }
    else
    {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", input1, input2);
    }

    return 0;
}
