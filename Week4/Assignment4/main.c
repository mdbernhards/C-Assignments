#include <stdio.h>
#include "functions.h"

char GameBoard[10][10];
int TreasureRow;
int TreasureColumn;

// Displays the game board array in console
void ShowGameBoard()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%c ", GameBoard[i][j]);
        }

        printf("\n");
    }
}

// Generates coordinates for the treasure
void GenerateTreasureCoordinates()
{
    TreasureRow = random_int(1,9);
    TreasureColumn = random_int(1,9);
}

// Creates the Game board array before start of the game
void CreateGameBoard()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            GameBoard[i][j] = '.';

            if (i == 0)
            {
                GameBoard[i][j] = j + '0';
            }
            else if (j == 0)
            {
                GameBoard[i][j] = i + '0';
            }
        }
    }

    GameBoard[0][0] = ' ';
}

// Checks if user found the treasure, displays the answer, returns true/false
int CheckIfTreasureFound(int enteredRow, int enteredColumn)
{
    if (enteredRow == TreasureRow && enteredColumn == TreasureColumn)
    {
        GameBoard[enteredRow][enteredColumn] = 'X';
        printf("You found the treasure!\n");

        return 1;
    }
    else
    {
        GameBoard[enteredRow][enteredColumn] = '+';

        int distance = max(enteredRow - TreasureRow, TreasureRow - enteredRow)
                + max(enteredColumn - TreasureColumn, TreasureColumn - enteredColumn);
        printf("Not here! The treasure is %d squares away.\n", distance);

        return 0;
    }
}

int main() {
    int isTreasureFound;

    CreateGameBoard();
    ShowGameBoard();
    GenerateTreasureCoordinates();

    do
    {
        int enteredRow = read_int("Enter row:");
        int enteredColumn = read_int("Enter column:");

        isTreasureFound = CheckIfTreasureFound(enteredRow,enteredColumn);
        ShowGameBoard();
    } while (!isTreasureFound);

    return 0;
}