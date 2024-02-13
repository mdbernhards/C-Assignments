#include <stdio.h>
#include "functions.h"

int main() {
    printf("I'm thinking of a number between 1 and 100...\n");

    int computerNumber = random_int(1, 100);
    int guessCount = 0, usersNumber;

    do {
        usersNumber = read_int("Guess the number: ");
        guessCount++;

        if (usersNumber > computerNumber)
        {
            printf("To high!\n");
        }
        else if (usersNumber < computerNumber)
        {
            printf("To low!\n");
        }

    } while (computerNumber != usersNumber);

    printf("You got it! It took you %d guesses", guessCount);

    return 0;
}