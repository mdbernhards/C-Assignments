#include <stdio.h>
#include <string.h>
#include <math.h>
#include "functions.h"

const int ARRAY_LENGTH = 100;

/// Checks if the string contains a valid coordinate in the form (x, y).
/// @param string The string to check.
/// @param x The memory address of the integer to store the x-component of the coordinate in.
/// @param y The memory address of the integer to store the y-component of the coordinate in.
/// @return `true` if the string contains a single integer, `false` otherwise.
bool readCoordinate(const char *string, int *x, int *y)
{
    if (sscanf(string, "(%d,%d)", x, y) == 2)
    {
        return true;
    } else
    {
        return false;
    }
}

/// Gets the coordinate from the user
void GetCoordinate(bool isFirstCoordinate, int *x, int *y, char * coordinate)
{
    bool validCoord = false;

    while (!validCoord)
    {
        if (isFirstCoordinate)
        {
            strcpy(coordinate, read_string("Please enter a coordinate:"));
        }
        else
        {
            strcpy(coordinate, read_string("Please enter another coordinate:"));
        }

        validCoord = readCoordinate(coordinate, x, y);

        if(!validCoord)
        {
            printf("Invalid input, please try again.\n");
        }
    }
}

float CalculateDistance(int coordArr[][2])
{
    return (float)sqrt(((coordArr[1][0]-coordArr[0][0])*(coordArr[1][0]-coordArr[0][0]))+
        ((coordArr[1][1]-coordArr[0][1])*(coordArr[1][1]-coordArr[0][1])));
}

int main(void)
{
    const int CoordinateCount = 2, Axis = 2;
    float calculation;

    char coordinate1[ARRAY_LENGTH],  coordinate2[ARRAY_LENGTH];
    int coordArr[CoordinateCount][Axis];

    GetCoordinate( true, &coordArr[0][0], &coordArr[0][1], coordinate1);
    GetCoordinate( false, &coordArr[1][0], &coordArr[1][1], coordinate2);

    calculation = CalculateDistance(coordArr);

    printf("The coordinates are %s and %s, and the distance between them is %.4f\n", coordinate1, coordinate2, calculation);

    return 0;
}
