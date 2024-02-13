#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

const int LENGTH = 100;
const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

/// Encodes a specific character
char EncodeCharacter(int index, int i)
{
    int newIndex = index + i + 1;

    if (newIndex > 51)
    {
        return (char)(alphabet[(newIndex % 52)]);
    }
    else
    {
        return (char)(alphabet[(newIndex)]);
    }
}

/// Decodes specific character
char DecodeCharacters(int index, int i)
{
    int newIndex = index - i - 1;

    if (newIndex < 0)
    {
        return (char)(alphabet[(newIndex + 52)]);
    }
    else
    {
        return (char)(alphabet[(newIndex)]);
    }
}

/// Encodes or Decodes specific sentence, based on bool encodeCharacters
void EncodeOrDecodeCharacters(char * sentence, bool encodeCharacters)
{
    for (int i = 0; i < (int)strlen(sentence); ++i)
    {
        if (isalpha(sentence[i]))
        {
            int index = strchr(alphabet, sentence[i]) - alphabet;
            if (encodeCharacters == true)
            {
                sentence[i] = EncodeCharacter(index, i);
            }
            else
            {
                sentence[i] = DecodeCharacters(index, i);
            }
        }
    }
}

int main(void)
{
    char sentence[LENGTH], decodedSentence[LENGTH];

    strcpy(sentence, read_string("Please enter a sentence:"));

    if ((int)strlen(sentence) == 0)
    {
        printf("Bye!\n");
        return 0;
    }

    EncodeOrDecodeCharacters(sentence, true);
    strcpy(decodedSentence, sentence);
    EncodeOrDecodeCharacters(sentence, false);

    printf("Encoded sentence: %s\n", decodedSentence);
    printf("Decoded sentence: %s\n", sentence);

    return 0;
}
