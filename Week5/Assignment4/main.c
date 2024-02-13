#include <stdio.h>
#include "functions.h"

const int ARRAY_SIZE = 20;

void InitializeArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = random_int(0, 9);
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

void MoveZerosToTheEnd(int array[])
{
    int insertPosition = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if(array[i] != 0)
        {
            array[insertPosition] = array[i];
            insertPosition++;
        }
    }

    while (insertPosition < ARRAY_SIZE)
    {
        array[insertPosition] = 0;
        insertPosition++;
    }
}

int main() {
    int array[ARRAY_SIZE];

    InitializeArray(array);

    DisplayArray(array, 20);

    MoveZerosToTheEnd(array);

    DisplayArray(array, 20);

    return 0;
}