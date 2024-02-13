#include <stdio.h>
#include "functions.h"

int main() {
    int firstDice, secondDice, diceCount[13] = {0};
    int timesToRollDice = read_int("How many times should the dice be rolled?");

    for (int i = 0; i < timesToRollDice; ++i)
    {
        firstDice = random_int(1,6);
        secondDice = random_int(1,6);

        diceCount[firstDice + secondDice]++;
    }

    for (int i = 0; i < 13; ++i)
    {
        if (diceCount[i] > 0)
        {
            printf("%d: %d\n",i, diceCount[i]);
        }
    }

    return 0;
}