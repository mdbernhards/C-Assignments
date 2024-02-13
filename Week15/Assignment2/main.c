#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

const int ARRAY_LENGTH = 1000;

/// Counts the number of words in the given sentence.
/// @param sentence the sentence to count the words in
/// @returns the number of words in the sentence
int count_words(const char *sentence)
{
    int count = 0;
    bool isWord = false;

    for (int i = 0; i < (int)strlen(sentence); i++)
    {
        if (isalnum(sentence[i]) || sentence[i] =='\'')
        {
            if (!isWord)
            {
                isWord = true;
                count++;
            }
        }
        else
        {
            isWord = false;
        }
    }

    return count;
}

int main(void)
{
    char input[ARRAY_LENGTH];

    while (1)
    {
        strcpy(input, read_string("Enter a sentence:"));

        int words = count_words(input);

        if (words == 0)
        {
            printf("Exiting program. Have a nice day!");
            break;
        }

        printf("The sentence contains %d %s.\n", words, (words == 1) ? "word" : "words");
    }

    return 0;
}
