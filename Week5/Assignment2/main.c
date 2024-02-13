#include <stdio.h>
#include "functions.h"

const int BIG_ARRAY_SIZE = 10;
const int SMALL_ARRAY_SIZE = 3;

void InitializeArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = random_int(1,10);
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
}

void GetUserInput(int smallArray[])
{
    for (int i = 0; i < SMALL_ARRAY_SIZE; ++i)
    {
        smallArray[i] = read_int("Enter a number:");
    }
}

int FindIfArrayContained(const int bigArray[],const  int smallArray[])
{
    for (int i = 0; i < BIG_ARRAY_SIZE - SMALL_ARRAY_SIZE + 1; ++i)
    {
        if (bigArray[i] == smallArray[0])
        {
            if (bigArray[i+1] == smallArray[1] && bigArray[i+2] == smallArray[2])
            {
                return i;
            }
        }
    }

    return -1;
}

void DisplayResults(int smallArray[], int containmentStartIndex)
{
    if (containmentStartIndex == -1)
    {
        printf("The array {");
        DisplayArray(smallArray, SMALL_ARRAY_SIZE);
        printf("} is not contained in the larger array.");
    }
    else
    {
        printf("The array {");
        DisplayArray(smallArray, SMALL_ARRAY_SIZE);
        printf("}  is contained in the larger array, starting at index %d", containmentStartIndex);
    }
}

int main(void)
{
    int bigArray[BIG_ARRAY_SIZE], smallArray[SMALL_ARRAY_SIZE], containmentStartIndex;

    InitializeArray(bigArray, BIG_ARRAY_SIZE);
    DisplayArray(bigArray, BIG_ARRAY_SIZE);
    printf("\n");

    GetUserInput(smallArray);

    containmentStartIndex = FindIfArrayContained(bigArray, smallArray);

    DisplayResults(smallArray, containmentStartIndex);

    return 0;
}
