#include <stdio.h>
#include "functions.h"
#include "math.h"

/// Asks the user to enter a valid operator, and returns the operator.
/// Valid operators are: +, -, *, /, ^ (exponentiation)
/// If the user enters an invalid operator, the user is asked again until a valid operator is entered.
/// @return The operator entered by the user.
char ReadOperator(void)
{
    char operator;

    while (1)
    {
        operator = read_char("Please enter an operator (+, -, *, /, ^):");

        if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^')
        {
            return operator;
        }
        else
        {
            printf("Please enter a valid operator! \n");
        }
    }

    // declare char operator
    // in while loop ask for operator with read_char
    // with 'if' check if the operator is one of these: +, -, *, /, ^
    // if it is return if not ask again

    return ' ';
}

/// Returns the result of applying the given operator to the given numbers.
/// @param number1 The first number.
/// @param number2 The second number.
/// @param operator The operator.
/// @return The result of applying the operator to the two numbers.
float ApplyOperator(float number1, float number2, char operator)
{
    switch (operator)
    {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            return number1 / number2;
        case '^':
            return pow(number1,number2);
        default:
            return 1337;
    }

    // have a switch case for each operation
    // for each case return number 1 and 2 with specific operation, like: number1 + number2 or number1 / number2, etc.

    return 0;
}

/// Asks the user whether they want to perform another calculation, and returns true if the user wants to perform another calculation, and false otherwise.
/// @return true if the user wants to perform another calculation, and false otherwise.
bool PerformAnotherCalculation(void)
{
    char usersChoice;

    while (true)
    {
        usersChoice = read_char("Do you want to continue? (y/n)");

        if (usersChoice == 'y')
        {
            return true;
        }
        else if (usersChoice == 'n')
        {
            return false;
        }
    }

    // declare char usersChoice

    // with read_char ask user if they want to continue with y/n assign answer to usersChoice

    // with if check: if users Choice is y return true and if not return false.
}

/// Prints out the calculation with correct operator and formatting.
/// @param number1 The first number.
/// @param number2 The second number.
/// @param number2 Result of the previous calculation.
/// @param operator The operator.
void DisplayCalculation(float number1, float number2, float result, char operator)
{
    printf("%.4f %c %.4f = %.4f \n", number1, operator, number2, result);
}

int main(void)
{
    bool anotherCalculation;

    do {
        float result, number1, number2;
        char operator;

        number1 = read_float("Please enter a number:");
        number2 = read_float("Please enter another number:");
        printf("\n");
        operator = ReadOperator();

        result = ApplyOperator(number1, number2, operator);
        DisplayCalculation(number1, number2, result, operator);

        anotherCalculation = PerformAnotherCalculation();
    } while (anotherCalculation);

    return 0;

    // in do while(anotherCalculation) loop:

        // declare char operator, float result

        // ask for two numbers using read_float()
        // call readOperator(void) assign return to operator
        // calculate using applyOperator(number1, number2, operator) assign to result

        // call DisplayCalculation(number1, number2, result, operator)

        // call performAnotherCalculation() return value assign to anotherCalculation.

    // do while loop ends
}
