#include <stdio.h>
#include "functions.h"

// chooses who starts the game randomly
int FlipCoin()
{
  int coinFlip = random_int(1,2);

  if(coinFlip == 1)
  {
      printf("You start!\n");
  }
  else
  {
      printf("CPU starts!\n");
  }

  return coinFlip;
}

// Takes users turn, validates user input and checks if user lost
int UsersTurn(int pretzelCount)
{
    printf("There are %d pretzels in the pile.\n", pretzelCount);

    int pretzelsToRemove = read_int("How many pretzels do you want to remove (1-3)? ");
    while (pretzelCount - pretzelsToRemove < 0 || pretzelsToRemove > 3 || pretzelsToRemove < 1)
    {
        printf("Invalid input, try again!\n");
        pretzelsToRemove = read_int("How many pretzels do you want to remove (1-3)? ");
    }

    pretzelCount -= pretzelsToRemove;

    if (pretzelCount == 0)
    {
        printf("You lose!\n");
        return 0;
    }

    return pretzelCount;
}

// Takes computers turn, checks if computer lost.
int ComputersTurn(int pretzelCount)
{
    int pretzelsToRemove;
    printf("There are %d pretzels in the pile.\n", pretzelCount);

    do {
        pretzelsToRemove = random_int(1,3);
    } while (pretzelCount - pretzelsToRemove < 0);

    pretzelCount -= pretzelsToRemove;

    printf("Computer removes %d pretzels.\n", pretzelsToRemove);

    if(pretzelCount == 0)
    {
        printf("You win!\n");
        return 0;
    }

    return  pretzelCount;
}

// At the start of the game asks user how many pretzels are in the pile, validates input.
int GetPretzelCount()
{
    int pretzelCount = read_int("How many pretzels are in the pile? ");
    while (pretzelCount  < 10 || pretzelCount > 50)
    {
        printf("Invalid input, try again!\n");
        pretzelCount = read_int("How many pretzels are in the pile? ");
    }

    return pretzelCount;
}

int main() {
    int coinFlip;

    printf("Welcome to the pretzel game!\n");
    int pretzelCount = GetPretzelCount();
    printf("I flip a coin to see who starts...\n");
    coinFlip = FlipCoin();

    if (coinFlip == 2)
    {
        pretzelCount = ComputersTurn(pretzelCount);
    }

    while (pretzelCount != 0)
    {
        pretzelCount = UsersTurn(pretzelCount);

        if (pretzelCount > 0)
        {
            pretzelCount = ComputersTurn(pretzelCount);
        }
    }

    return 0;
}