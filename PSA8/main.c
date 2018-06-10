/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA8
 Student        : David
 Date submitted	: 3/15/2017
 Description	: In this PSA you will build a command line calculator. This is just a simple four function calculator. However, there are some specifics on how to build it. First, each function must be accomplished using -- not surprisingly -- a function(). The operations must be decoded using a switch statement. Submit your code as usual.
 Extra comments : The steps of the program (or pseudocode) are the comments inside main(), each line comment is a step. The comments to the right of a line of code, gives more details about that specific code.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Function addition(double x, double y)
 * Adds y to x and return the result
*/
double addition (double x, double y) {
    return (x + y);
}

/*
 * Function subtraction(double x, double y)
 * Subtracts y from x and return the result
*/
double subtraction (double x, double y) {
    return (x - y);
}

/*
 * Function multiplication(double x, double y)
 * Multiplies y to x and return the result
*/
double multiplication (double x, double y) {
    return (x * y);
}

/*
 * Function division(double x, double y)
 * Divides x by y and return the result
*/
double division (double x, double y) {
    return (x / y);
}


/*
 * Main
*/
int main()
{
    // Set variables
    double x = 0, y = 0;        // initializes variables x and y as 0
    char operation;             // defines variable operation, which will save the operator given by the user
    double result;              // defines the variable to save the operation result

    // Get the user input
    scanf("%lf", &x);           // get the first number
    scanf("%c", &operation);    // get the operator
    scanf("%lf", &y);           // get the second number

    // Makes the calculation using a switch statement
    switch(operation) {
    case '+':
            result = addition(x, y);        // calls addition function
            break;
        case '-':
            result = subtraction(x, y);     // calls subtraction function
            break;
        case '*':
            result = multiplication(x, y);  // calls multiplication function
            break;
        case '/':
            result = division(x, y);        // calls division function
            break;
        default:
            break;
    }

    // Print the result to the user
    printf("The result of %lf %c %lf is %lf .", x, operation, y, result);

    // Exit main
    return 0;
}
