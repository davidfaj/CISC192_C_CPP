/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA6
 Student        : David
 Date submitted	: 3/4/2017
 Description	: This program is a simplified version of a US Federal Income Tax Calculator. Simplified because it assumes that the user has no deductions, credits, or other factors to take into account. Also that the user is single.
 Extra comments1: The steps of the program (or pseudocode) are the comments inside main(), each line comment is a step. The comments to the right of a line of code, gives more details about that specific code.
 Extra comments2: I was trying to assign the detailed explanation of the bracket to a char[] and I couldn't do it by just using the "=" operator, so I researched on the internet and found the method strcpy(). I know that we weren't taught that yet, but as it's a simple method, doesn't need any additional library to be included and I have experience in other programming languages, I feel safe of using it, I understand what's going on.
  Extra comments3: If I was using a programming language that I know, I was going to create a 2d array with the table parameters and loop on it. I researched a little bit about different type 2d arrays in C and I saw that this is a little bit complex and different than other languages, so I'll leave it for a future project.

 ============================================================================
 */

#include <stdio.h>  // Standard I/O library

int main() {
    /*
     * Set the program variables
     */
	char userName[80];				// user name
	double grossIncome;				// user's gross income in 2017
	int bracketLevel = 0;			// bracket level on IRS table
	double bracketInitialTax;		// initial tax to be paid according to bracket level
	double bracketTaxRate;			// tax rate according to bracket level
	double bracketLowerLimit;		// lower limit of bracket level
	double taxOwed;					// total tax owed
	double effectiveTaxRate;		// effective tax rate
	char bracketExplanation[80];	// text explanation of tax calculation according to bracket level


    /*
     * Ask and save the user's name and gross income
     */
	printf("Hello, what is your name? ");
	scanf("%s", userName);		// assign the answer to its variable
	printf("%s, what is your total gross income in 2017? ", userName);
	scanf("%lf", &grossIncome);	// assign the answer to its variable


	/*
	 * Using if-else-if statements, calculate all the necessary values, according to the following logic:
	 * 1) Each if/else statement is used to check on which bracket level the gross income falls
	 * 2) According to the bracket level:
	 * 		a) set the bracket level
	 * 		b) set the initial tax
	 * 		c) set the tax rate
	 * 		d) set the lower limit
	 * 		e) calculate the tax owed
	 * 		f) calculate the effective tax rate
	 * 		g) set the explanation text for the calculation
	 *
	 * 	Observation: The logic of the tax calculation is that, for each tax bracket, "tax owed" = "initial tax" + ("tax rate" * ("income - lowerLimit") ). To make things easier (and in compliance with the IRS table), I consider that the first tax bracket has an "initial tax" of $0.00 and the lowerLimit is $0.00 (using words similar to the table, it would be: "$0.00 plus 0% of the excess over $0.00" for level 1).
	 */
	if(grossIncome<=9325) {
		bracketLevel = 1;
		bracketInitialTax = 0.0;
		bracketTaxRate = 0.10;
		bracketLowerLimit = 0.0;
		taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
		effectiveTaxRate = taxOwed / grossIncome;
		strcpy(bracketExplanation, "10% of Taxable Income");
	}
	else if(grossIncome<=37950) {
		bracketLevel = 2;
		bracketInitialTax = 932.50;
		bracketTaxRate = 0.15;
		bracketLowerLimit = 9325.0;
		taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
		effectiveTaxRate = taxOwed / grossIncome;
		strcpy(bracketExplanation, "$932.50 plus 15% of the excess over $9325");
	}
	else if(grossIncome<=91900) {
			bracketLevel = 3;
			bracketInitialTax = 5226.25;
			bracketTaxRate = 0.25;
			bracketLowerLimit = 37950.0;
			taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
			effectiveTaxRate = taxOwed / grossIncome;
			strcpy(bracketExplanation, "$5,226.25 plus 25% of the excess over $37,950");
		}
	else if(grossIncome<=191650) {
				bracketLevel = 4;
				bracketInitialTax = 18713.75;
				bracketTaxRate = 0.28;
				bracketLowerLimit = 91900.0;
				taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
				effectiveTaxRate = taxOwed / grossIncome;
				strcpy(bracketExplanation, "$18,713.75 plus 28% of the excess over $91,900");
			}
	else if(grossIncome<=416700) {
					bracketLevel = 5;
					bracketInitialTax = 46643.75;
					bracketTaxRate = 0.33;
					bracketLowerLimit = 191650.0;
					taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
					effectiveTaxRate = taxOwed / grossIncome;
					strcpy(bracketExplanation, "$46,643.75 plus 33% of the excess over $191,650");
				}
	else if(grossIncome<=418400) {
						bracketLevel = 6;
						bracketInitialTax = 120910.25;
						bracketTaxRate = 0.35;
						bracketLowerLimit = 416700.0;
						taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
						effectiveTaxRate = taxOwed / grossIncome;
						strcpy(bracketExplanation, "$120,910.25 plus 35% of the excess over $416,700");
					}
	else {
						bracketLevel = 7;
						bracketInitialTax = 121505.25;
						bracketTaxRate = 0.396;
						bracketLowerLimit = 418400.0;
						taxOwed = bracketInitialTax + ( bracketTaxRate * (grossIncome - bracketLowerLimit) );
						effectiveTaxRate = taxOwed / grossIncome;
						strcpy(bracketExplanation, "$121,505.25 plus 39.6% of the excess over $418,400");
						}

	/*
	 * Display a Tax Statement with the detailed values to the user
	 */
	printf("\n------- Detailed Tax Statement: -------\n-\n");
	printf("- Gross income: $%.2lf\n", grossIncome);
	printf("- Tax bracket level in IRS table: %d (%s)\n", bracketLevel, bracketExplanation);
	printf("- Tax owed: $%.2lf\n", taxOwed);
	printf("- Tax owed calculation:  ($%.2lf + (%.1lf%% * ($%.2lf - $%.2lf)) = $%.2lf\n", bracketInitialTax, (bracketTaxRate * 100), grossIncome, bracketLowerLimit, taxOwed);
	printf("- Effective tax rate: %.2lf%%\n", (effectiveTaxRate * 100));
	printf("- Effective tax rate calculation: (%.2lf / %.2lf) = %.2lf%%\n-\n", taxOwed, grossIncome, (effectiveTaxRate * 100));
	printf("---------------------------------------\n");


	/*
	 * End program
	 */
	return 0;
}
