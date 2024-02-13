#include <stdio.h>
#include "functions.h"

int main() {
    int number = 1, columnCount = 1;
    int usersChoice = read_int("Enter a number (1-99):");

    while (1)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            if(number < 10)
            {
                printf(" %d ", number);
            }
            else
            {
                printf("%d ", number);
            }

            if(number == usersChoice)
            {
                return 0;
            }

            number++;
        }

        columnCount++;
        printf("\n");
    }
}