#include <stdio.h>
#include "functions.h"

int main() {
    int firstNumber = 0, secondNumber = 0, usersNumber;

    usersNumber = read_int("Please enter a number: ");

    while (usersNumber != 0)
    {
        if (usersNumber > firstNumber || firstNumber == 0)
        {
            secondNumber = firstNumber;
            firstNumber = usersNumber;
        }
        else if (usersNumber > secondNumber || secondNumber == 0)
        {
            secondNumber = usersNumber;
        }

        usersNumber = read_int("Please enter a number: ");
    }

    if (firstNumber == 0 || secondNumber == 0)
    {
        printf("Not enough numbers were entered.");
    }
    else
    {
        printf("The second-highest number that you entered is %d.", secondNumber);
    }

    return 0;
}