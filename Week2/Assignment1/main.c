#include <stdio.h>
#include "functions.h"

int main() {
    const float pi = 3.14159265358979323846;

    float radius = read_float("Please enter the radius of the circle: ");
    float area = radius * radius * pi;

    printf("The surface area of a circle with radius %.2f is %.2f", radius, area);

    return 0;
}