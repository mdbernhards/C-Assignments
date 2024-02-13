#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

const int LENGTH = 100;

/// Counts a specific sentence element, based on what char array is passed to this function
int CountElement(const char * sentence, const char * elements, int lenght)
{
    int elementCount = 0;

    for (int i = 0; i < (int)strlen(sentence); ++i)
    {
        for (int j = 0; j < lenght; ++j)
        {
            if (tolower(elements[j]) == tolower(sentence[i]))
            {
                elementCount++;
            }
        }
    }

    return elementCount;
}

/// Counts Vowels, Consonants, Digits in the given sentence.
int * CountElements(const char * sentence, int elementCount[])
{
    char Vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char Consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N',
                         'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    char Digits[] = {'0', '1', '2', '3', '4','5', '6', '7', '8', '9'};

    elementCount[0] = CountElement(sentence, Vowels, 5);
    elementCount[1] = CountElement(sentence, Consonants, 21);
    elementCount[2] = CountElement(sentence, Digits, 10);

    return elementCount;
}

int main(void)
{
    char sentence[LENGTH];
    int elementCount[] = {0,0,0};

    strcpy(sentence, read_string("Please enter a sentence:"));

    if ((int)strlen(sentence) == 0)
    {
        printf("Bye!\n");
        return 0;
    }

    CountElements(sentence, elementCount);

    printf("Vowels: %d\n", elementCount[0]);
    printf("Consonants: %d\n", elementCount[1]);
    printf("Digits: %d\n", elementCount[2]);

    return 0;
}
