#include <stdio.h>
#include "functions.h"

int main() {
    float usersNumber, numberArray[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 10; ++i)
    {
        usersNumber = read_float("Enter a number (0 to stop): ");
        if (usersNumber == 0)
        {
            break;
        }

        numberArray[i] = usersNumber;
    }

    printf("Flipped and reversed: ");

    for (int i = 9; i >= 0; i--)
    {
        if (numberArray[i] != 0)
        {
            printf(" %.2f", numberArray[i] * -1);

            if (i > 0)
            {
                printf(",");
            }
        }
    }

    return 0;
}