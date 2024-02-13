#include <stdio.h>
#include "functions.h"

int UserWins = 0, ComputerWins = 0;

// Prints out winner of the round, only called when it isn't a draw
void GetWinner(char computersChoice, char loseCondition)
{
    if (computersChoice == loseCondition)
    {
        printf("You lose!\n");
        ComputerWins++;
    }
    else
    {
        printf("You win!\n");
        UserWins++;
    }
}

// Prints out the outcome of the round
void GetResults(char usersChoice, char computersChoice)
{
    if (usersChoice == computersChoice)
    {
        printf("It's a draw!\n");
    }
    else
    {
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
                printf("error\n");
        }
    }
}

// Gets full name of a chosen item
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

// Generates computers choice and returns it
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
        default:
            return ' ';
    }
}

int main() {
    char usersChoice;

    printf("Rock, paper, scissors!\n");

    do
    {
        usersChoice = read_char("Please enter your choice (r, p, s, q): ");

        if(usersChoice == 'q')
        {
            printf("Final score: You %d, computer %d\n", UserWins, ComputerWins);
            return 0;
        }

        char computersChoice = GetComputersChoice();

        printf("You chose %s!\n", GetFullName(usersChoice));
        printf(" Computer chose %s!\n", GetFullName(computersChoice));

        GetResults(usersChoice, computersChoice);

        printf("Score: You %d, computer %d\n", UserWins, ComputerWins);
    } while (1);
}