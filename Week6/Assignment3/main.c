#include <stdio.h>
#include "functions.h"

int const ARRAY_SIZE = 3;

/// Checks if year is a leap year.
/// @param year The year being checked.
/// @return True if leap year.
bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }

    return false;

    // Check if a year is a leap year, if it is return true, otherwise return false
    // The formula:
    // A year is a leap year if:
    // It can be divided by 4 and can't be divided by 100
    // Or if it can be divided by 400
}

/// Gets the amount of days in a specific month in a specific year.
/// @param month The month.
/// @param year The year.
/// @return The amount of days in a specific month and year.
int GetDaysInASpecificMonth(int month, int year)
{
    bool isLeapYear;

    switch (month)
    {
        case 1:
        case 4:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 3:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            isLeapYear = IsLeapYear(year);
            break;
        default:
            return -1;
    }

    if (isLeapYear)
    {
        return 29;
    }

    return 28;

    // use switch case with 3 cases: months with 31 days, with 30 days, february
    // for 31 and 30 just return the days

    // for february call IsLeapYear(year) if true return 29 days, if not return 28 days
}

/// Checks if the given date is valid.
/// @param day Day of the date.
/// @param month Month of the date.
/// @param year Year of the date.
/// @return true if date is valid.
bool IsDateValid(int day, int month, int year)
{
    if (day <= 0 || month <= 0 || year <= 0 || month > 12)
    {
        return false;
    }

    int daysInAMonth = GetDaysInASpecificMonth(month, year);

    if (day > daysInAMonth)
    {
        return false;
    }

    return true;

    // check if all numbers positive
    // checks if month less than 12
    // using GetDaysInASpecificMonth(month, year) check if there are not too many days

    // if all true return true, else return false
}

/// Gets a date from the user and assigns it to a size 3 array.
/// @param dateArray Array of size three for the date.
void GetDate(int dateArray[])
{
    string nameArray[] = {"day", "month", "year"};

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Please enter a %s:", nameArray[i]);
        dateArray[i] = read_int("");
    }

    // declare nameArray[3] with {day, month, year} in it

    // create a for loop: for(int i = 0; i < ARRAY_SIZE; i++)
        // in it ask user for a specific day, month, year with read_int()
        // like: dateArray[i] = read_int("give %c:",nameArray[i]);
   // loop ends
}

/// Gets a date from the user, assigns it to a size 3 array and validates it.
/// @param dateArray Array of size three for the date.
void GetValidDate(int dateArray[])
{
    bool isDateValid = true;

    do
    {
        if (!isDateValid)
        {
            printf("Invalid date!\n");
        }

        GetDate(dateArray);
        isDateValid = IsDateValid(dateArray[0],dateArray[1],dateArray[2]);
    } while (!isDateValid);

    // create a do while loop for checking if date is valid
        // using GetDate(dateArray) get a date from the user
        // using IsDateValid(dateArray[0],dateArray[1],dateArray[2]) check if date valid,
        // if it is return true and end do while loop, otherwise return false and continue;
    // loop ends
}

/// Gets the day of the year of a specific date.
/// @param day The day of the date.
/// @param month The month of the date.
/// @param year The year of the date.
/// @return The day of the year of the specific date given.
int GetDayOfTheYear(int day, int month, int year)
{
    int dayOfTheYear = 0;

    for (int i = 1; i < month; i++)
    {
        dayOfTheYear += GetDaysInASpecificMonth(i, year);
    }

    dayOfTheYear += day;
    return dayOfTheYear;

    // Create a for loop: for(int i = 1; i < month)
        // sum up all months before the given month using GetDaysInASpecificMonth(i, year)
        // like dayOfTheYear +=  GetDaysInASpecificMonth(i, year)
    // loop ends

    // add day to dayOfTheYear and return it
}

int main(void)
{
    int dateArray[ARRAY_SIZE], dayOfTheYear;

    GetValidDate(dateArray);
    dayOfTheYear = GetDayOfTheYear(dateArray[0], dateArray[1], dateArray[2]);

    printf("%d-%d-%d is day %d of the year", dateArray[0], dateArray[1], dateArray[2], dayOfTheYear);

    return 0;
}
