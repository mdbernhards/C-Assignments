#include <stdio.h>
#include "functions.h"

const int ARRAY_LENGTH = 10;

/// Prints the array to the console, values comma-separated and on a single line
/// @param array The array to print.
/// @param length The length of the array.
void print_array(const int array[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d", array[i]);

        if (i < length - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

/// Swaps the values of the two integers pointed to by `a` and `b`.
/// @param a The memory address of the first integer.
/// @param b The memory address of the second integer.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// Returns the address of the smallest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the smallest number in the array, or NULL if the array is empty.
int *min_ptr(int array[], int length)
{
    if (length == 0)
    {
        return NULL;
    }

    int *min = &array[0];

    for (int i = 1; i < length; ++i)
    {
        if (array[i] < *min)
        {
            min = &array[i];
        }
    }

    return min;
}

/// Returns the address of the largest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the largest number in the array, or NULL if the array is empty.
int *max_ptr(int array[], int length)
{
    if (length == 0)
    {
        return NULL;
    }

    int *max = &array[0];

    for (int i = 1; i < length; ++i)
    {
        if (array[i] > *max)
        {
            max = &array[i];
        }
    }

    return max;
}

int main(void)
{
    int numbers[ARRAY_LENGTH];

    for (int i = 0; i < ARRAY_LENGTH; ++i)
    {
        numbers[i] = random_int(0, 100);
    }

    printf("The array is: ");
    print_array(numbers, ARRAY_LENGTH);

    int *min = min_ptr(numbers, ARRAY_LENGTH);
    int *max = max_ptr(numbers, ARRAY_LENGTH);

    printf("The smallest number is %d, and the largest number is %d.\n", *min, *max);

    swap(min, max);

    printf("After swapping, the array is: ");
    print_array(numbers, ARRAY_LENGTH);

    return 0;
}
