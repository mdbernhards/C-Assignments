#include <stdio.h>
#include "functions.h"

struct coordinate_t {
    int x;
    int y;
};

struct triangle_t {
    struct coordinate_t coord1;
    struct coordinate_t coord2;
    struct coordinate_t coord3;
};

void print_triangle(const struct triangle_t* triangle){
    printf("(%d, %d)\n", triangle->coord1.x, triangle->coord1.y);
    printf("(%d, %d)\n", triangle->coord2.x, triangle->coord2.y);
    printf("(%d, %d)\n", triangle->coord3.x, triangle->coord3.y);
}

void rotate_coordinate(struct coordinate_t* coordinate){
    int tempX = coordinate->x;
    coordinate->x = coordinate->y * -1;
    coordinate->y = tempX;
}

void rotate_triangle(struct triangle_t* triangle){
    rotate_coordinate(&triangle->coord1);
    rotate_coordinate(&triangle->coord2);
    rotate_coordinate(&triangle->coord3);
}

int main(void)
{
    struct triangle_t triangle;
    triangle.coord1.x = 1;
    triangle.coord1.y = 3;
    triangle.coord2.x = 2;
    triangle.coord2.y = 5;
    triangle.coord3.x = 3;
    triangle.coord3.y = 8;

    printf("Triangle coordinates: \n");
    print_triangle(&triangle);

    rotate_triangle(&triangle);

    printf("Rotated triangle coordinates: \n");
    print_triangle(&triangle);

}
