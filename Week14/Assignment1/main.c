#include <stdio.h>
#include <math.h>
#include "functions.h"

typedef struct {
    int x;
    int y;
} coordinate_t;

/// Uses the console to read a coordinate from the user.
/// @param prompt The prompt to display to the user.
/// @return The coordinate entered by the user.
coordinate_t ReadCoordinate(const char *prompt)
{
    coordinate_t coordinate;

    sscanf(prompt, "%d,%d", &coordinate.x, &coordinate.y);

    return coordinate;
}

/// Gets the coordinate from the user
void GetCoordinate(bool isFirstCoordinate, coordinate_t *coordinate)
{
    const char * rawCoordinate;

    if (isFirstCoordinate)
    {
        rawCoordinate = read_string("Please enter a coordinate:");
    }
    else
    {
        rawCoordinate = read_string("Please enter another coordinate:");
    }

    *coordinate = ReadCoordinate(rawCoordinate);
}

/// Calculates the distance between two coordinates.
/// @param a The first coordinate.
/// @param b The second coordinate.
/// @return The distance between the two coordinates.
float Distance(const coordinate_t *a, const coordinate_t *b)
{
    return (float)sqrt(((a->x - b->x) * (a->x - b->x)) + ((a->y - b->y) * (a->y - b->y)));
}

int main(void)
{
    float calculation;

    coordinate_t coordinate1;
    coordinate_t coordinate2;

    GetCoordinate( true, &coordinate1);
    GetCoordinate( false, &coordinate2);

    calculation = Distance(&coordinate1, &coordinate2);

    printf("The distance between (%i,%i) and (%i,%i) is %.2f\n",
           coordinate1.x, coordinate1.y, coordinate2.x, coordinate2.y, calculation);

    return 0;
}
