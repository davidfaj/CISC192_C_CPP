/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Name			: main.c
 Student		: David
 Assignment		: PSA4
 Description	: Using only C, create a program that instantiates an uninitialized character array. Using only numerical values populate the array with the character values "cisc 192" (note the lower case). Display this string on the console. Next, using only subtraction  convert the characters in the string to form the string "CISC 192" (again, note the case). Again display the string on the console. Zip your project and submit as usual.
 ============================================================================
 */

#include <stdio.h>
//#include <stdlib.h>

int main() {
	// Instantiates an uninitialized character array called 'str' with 9 bits
	char str[9];

	// Populates the array using character values (I used ASCII table to get these values)
	str[0] = 99;
	str[1] = 105;
	str[2] = 115;
	str[3] = 99;
	str[4] = 32;
	str[5] = 49;
	str[6] = 57;
	str[7] = 50;
	str[8] = 0;

	// Display this string on the console
	printf("%s\n", str);

	// Convert the characters in the array to upper case using substraction
	#define DIFF 32;	// looking to the ASCII table, it's possible to identify that the all upper case letters are 32 bigger than their correspondent lower cases (decimal value of upper case - decimal value of lower case)
	str[0] -= DIFF;
	str[1] -= DIFF;
	str[2] -= DIFF;
	str[3] -= DIFF;

	// Display this string on the console
	printf("%s\n", str);

	return 0;
}
