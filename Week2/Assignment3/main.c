#include <stdio.h>
#include "functions.h"

int main() {
    int enteredNumber = read_int("Please enter a three-digit number: ");
    int firstNumber, secondNumber, thirdNumber;

    if (enteredNumber < 100 || enteredNumber > 999)
    {
        printf("Sorry for the inconvenience, but that's not a three-digit number! :(");
        return 1;
    }

    firstNumber = enteredNumber / 100;
    secondNumber = enteredNumber / 10 % 10;
    thirdNumber = enteredNumber % 10;

    printf("The reverse of %d is %d%d%d.", enteredNumber, thirdNumber, secondNumber, firstNumber);

    return 0;
}