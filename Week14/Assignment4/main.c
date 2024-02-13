#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

/// Starting with position, finds the first character that
/// is printable and not whitespace or punctuation.
/// @param position the address at which the search is started
/// @returns the address of the first word-character, or NULL if no
///   such character could be found.
char *find_first_word_character(char *position)
{
    while (*position != '\0' && !isalnum(*position))
    {
        position++;
    }

    return (*position == '\0') ? NULL : position;
}

/// Starting with position, finds the first character that
/// is whitespace, punctuation, or non-printable.
char *find_first_non_word_character(char *position)
{
    while (*position != '\0' && isalnum(*position))
    {
        position++;
    }

    return (*position == '\0') ? NULL : position;
}

/// Reverses the characters in the string starting and ending at the given positions.
/// @param begin the address at which the string to be reversed starts
/// @param end the address at which the string to be reversed ends
void reverse_string(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/// Checks if a string is empty (i.e., consists only of whitespace).
/// @param string the string to check
/// @returns true if the string is empty, false otherwise.
bool is_empty(const char *string)
{
    while (*string != '\0')
    {
        if (!isspace(*string))
        {
            return false;
        }

        string++;
    }

    return true;
}

int main(void) {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];
    char *word_start, *word_end;

    while (true)
    {
        strcpy(input, read_string("Enter a sentence:"));

        if (is_empty(input))
        {
            printf("No more input, exiting program.\n");
            break;
        }

        word_start = find_first_word_character(input);

        while (word_start != NULL)
        {
            word_end = find_first_non_word_character(word_start);

            if (word_end != NULL)
            {
                reverse_string(word_start, word_end - 1);
                word_start = find_first_word_character(word_end);
            }
            else
            {
                reverse_string(word_start, &input[strlen(input) - 1]);
                break;
            }
        }

        printf("%s\n", input);
    }

    return 0;
}
