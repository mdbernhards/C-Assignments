#include <stdio.h>
#include "functions.h"

const int ARRAY_SIZE = 10;

void InitializeArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = random_int(1, 10);
    }
}

void DisplayArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        if (i == arraySize-1)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }

    printf("\n");
}

int AskUserNumber(void)
{
    int userNumber;

    while (1)
    {
        userNumber = read_int("Enter a number (1-10):");

        if (userNumber >= 1 && userNumber <= 10)
        {
            return userNumber;
        }
        else
        {
            printf("That's not a valid input.\n");
        }
    }
}

void CondenseTheArray(int array[], int index)
{
    for (int i = index; i < ARRAY_SIZE - 1; ++i)
    {
        array[i] = array[i+1];
        array[i+1] = 0;
    }
}

int RemoveMatchingValues(int array[], int number)
{
    int numberOfElements = ARRAY_SIZE;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if(array[i] == number)
        {
            CondenseTheArray(array, i);
            numberOfElements--;
            i--;
        }
    }

    return numberOfElements;
}

int main(void) {
    int array[ARRAY_SIZE], userNumber, numberOfElements;
    InitializeArray(array);

    DisplayArray(array, ARRAY_SIZE);
    userNumber = AskUserNumber();

    numberOfElements = RemoveMatchingValues(array, userNumber);

    DisplayArray(array,numberOfElements);

    return 0;
}
