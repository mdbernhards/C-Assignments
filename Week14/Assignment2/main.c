#include <stdio.h>
#include "functions.h"

typedef struct {
    int red;
    int green;
    int blue;
} color_t;

color_t read_color(const char *prompt)
{
    color_t newColor;
    printf("%s", prompt);
    printf("Enter the red component: ");
    newColor.red = read_int("");
    printf("Enter the green component: ");
    newColor.green = read_int("");
    printf("Enter the blue component: ");
    newColor.blue = read_int("");

    return newColor;
}

void print_color(const color_t *color)
{
    printf("The colour is #%02x%02x%02x.\n", color->red, color->green, color->blue);
}

void increase_brightness(color_t *color)
{
    color->red = (int)(color->red / 0.7);
    color->green = (int)(color->green / 0.7);
    color->blue = (int)(color->blue / 0.7);

    color->red = (color->red > 255) ? 255 : color->red;
    color->green = (color->green > 255) ? 255 : color->green;
    color->blue = (color->blue > 255) ? 255 : color->blue;
}

void decrease_brightness(color_t *color)
{
    color->red = (int)(color->red * 0.7);
    color->green = (int)(color->green * 0.7);
    color->blue = (int)(color->blue * 0.7);
}

int main(void) {
    color_t currentColor = read_color("Enter the initial color:\n");
    print_color(&currentColor);

    char choice;

    do
    {
        printf("Do you want to increase (i) or decrease (d) the brightness (q to quit)? ");
        scanf(" %c", &choice);

        if (choice == 'i')
        {
            increase_brightness(&currentColor);
        }
        else if (choice == 'd')
        {
            decrease_brightness(&currentColor);
        }
        else if (choice != 'q')
        {
            printf("Invalid choice. Please enter 'i', 'd', or 'q'.\n");
        }

        print_color(&currentColor);
    } while (choice != 'q');

    printf("Bye!\n");

    return 0;
}
