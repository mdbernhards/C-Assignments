#include <stdio.h>
#include "functions.h"

const int ARRAY_SIZE = 10;
const int ARRAY_MAX = 99;
const int ARRAY_MIN = 1;

/// Prints the contents of the given array to the console, comma-separated and on a single line.
/// @param array The array to print.
/// @param arraySize The size of the array (i.e., number of elements).
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

/// Fills the given array with random integer numbers between min and max (inclusive).
/// @param array The array to fill.
/// @param arraySize The size of the array (i.e., number of elements).
/// @param min The minimum value of the random numbers.
/// @param max The maximum value of the random numbers.
void InitializeArray(int array[], int arraySize, int min, int max)
{
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = random_int(min,max);
    }
}

/// Reverses the contents of the given array.
/// @param array The array to reverse.
/// @param arraySize The size of the array (i.e., number of elements).
void ReverseArray(int array[], int arraySize)
{
    int lastIndex = ARRAY_SIZE - 1;

    for (int i = 0; i < arraySize / 2; i++)
    {
        int temp = array[i];
        array[i] = array[lastIndex];
        array[lastIndex] = temp;
        lastIndex--;
    }
}

int main(void)
{
    int array[ARRAY_SIZE];

    InitializeArray(array, ARRAY_SIZE, ARRAY_MIN, ARRAY_MAX);

    printf("The array contains: ");
    DisplayArray(array, ARRAY_SIZE);

    ReverseArray(array, ARRAY_SIZE);

    printf("After reverse:      ");
    DisplayArray(array, ARRAY_SIZE);

    return 0;
}
