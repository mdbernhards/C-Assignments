#include <stdio.h>
#include "functions.h"

void GetWinner(char computersChoice, char loseCondition)
{
    if (computersChoice == loseCondition)
    {
        printf("You lose!");
    }
    else
    {
        printf("You win!");
    }
}

string GetFullName(char shortName)
{
    switch (shortName)
    {
        case 'r':
            return "rock";
        case 'p':
            return "paper";
        case 's':
            return "scissors";
        default:
            return "error";
    }
}

char GetComputersChoice(void)
{
    switch(random_int(1, 3))
    {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
    }
}

int main() {
    char usersChoice = read_char("Please enter your choice (r = rock, p = paper, s = scissors): ");
    char computersChoice = GetComputersChoice();

    printf("You chose %s!\n", GetFullName(usersChoice));
    printf(" Computer chose %s!\n", GetFullName(computersChoice));

    if (usersChoice == computersChoice)
    {
        printf("It's a draw!");
        return 0;
    }

    switch (usersChoice)
    {
        case 'r':
            GetWinner(computersChoice, 'p');
            break;
        case 'p':
            GetWinner(computersChoice, 's');
            break;
        case 's':
            GetWinner(computersChoice, 'r');
            break;
        default:
            printf("error");
    }

    return 0;
}