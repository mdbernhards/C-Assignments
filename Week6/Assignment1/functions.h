#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

typedef const char * string;

/// Reads an integer from the user.
/// @param prompt The prompt to display to the user.
/// @return The integer entered by the user.
int read_int(string prompt);

/// Reads a float from the user.
/// @param prompt The prompt to display to the user.
/// @return The float entered by the user.
float read_float(string prompt);

/// Reads a character from the user.
/// @param prompt The prompt to display to the user.
/// @return The character entered by the user.
char read_char(string prompt);

/// Generates a random integer between min and max (inclusive).
/// @param min The minimum value of the random number.
/// @param max The maximum value of the random number.
int random_int(int min, int max);

/// Generates a random float between min and max (inclusive).
/// @param min The minimum value of the random number.
/// @param max The maximum value of the random number.
float random_float(float min, float max);

/// Returns the maximum of two integers.
/// @param a The first integer.
/// @param b The second integer.
/// @return The maximum of a and b.
int max(int a, int b);

/// Returns the minimum of two integers.
/// @param a The first integer.
/// @param b The second integer.
/// @return The minimum of a and b.
int min(int a, int b);

/// Returns the current date by filling an array
/// with the current year, month, and day.
/// @param date_parts An array of at least 3 integers.
/// @return True if the date was successfully retrieved,
///         false otherwise.
bool get_current_date(int date_parts[static 3]);

/// Returns the current time by filling an array
/// with the current hour, minute, and second.
/// @param time_parts An array of at least 3 integers.
/// @return True if the time was successfully retrieved,
///         false otherwise.
bool get_current_time(int time_parts[static 3]);
#endif //FUNCTIONS_H