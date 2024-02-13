#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

const int LENGTH = 100;

/// Returns true if the given sentence is valid, and false otherwise.
/// A sentence is valid if it contains at least one non-whitespace character.
/// @param sentence The sentence to analyze.
/// @return True if the sentence is valid, false otherwise.
bool is_valid_sentence(const char * sentence)
{
    for (int i = 0; i < (int)strlen((sentence)); ++i) {
        if (sentence[i] != ' ')
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    char shortestSentence[LENGTH], longestSentence[LENGTH], tempSentence[LENGTH];
    bool isStopEntered = false;

    strcpy(shortestSentence, "");
    strcpy(longestSentence, "");

    while (!isStopEntered)
    {
        strcpy(tempSentence, read_string("Please enter a sentence:"));

        if (strlen(shortestSentence) == 0)
        {
            strcpy(shortestSentence, tempSentence);
        }

        if (is_valid_sentence(tempSentence))
        {
            if (strcmp(tempSentence, "stop") == 0)
            {
                isStopEntered = true;
            }
            else if (strlen(shortestSentence) > strlen(tempSentence))
            {
                strcpy(shortestSentence, tempSentence);
            }
            else if (strlen(longestSentence) < strlen(tempSentence))
            {
                strcpy(longestSentence, tempSentence);
            }
        }
        else
        {
            printf("Invalid input!\n");
        }
    }

    printf("The shortest sentence is: %s\n", shortestSentence);
    printf("The longest sentence is: %s\n", longestSentence);

    return 0;
}
