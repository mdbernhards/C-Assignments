#include <stdio.h>
#include "functions.h"

const int ARRAY_SIZE = 10;

void DisplayArray(float array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("%5.1f, ", array[i]);
    }

    printf("\n");
}

void InitializeArray(float array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = random_float(-10,10);
    }
}

float CalculateTheMean(const float array[])
{
    float arraySum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arraySum += array[i];
    }

    return arraySum / (float)ARRAY_SIZE;
}

void RemoveTheMean(float array[])
{
    float arrayMean = CalculateTheMean(array);

    printf("Mean: %.2f \n", arrayMean);

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] -= arrayMean;
    }
}

int main() {
    float array[ARRAY_SIZE];

    InitializeArray(array);

    printf("Before: ");
    DisplayArray(array);

    RemoveTheMean(array);

    printf("After: ");
    DisplayArray(array);

    return 0;
}