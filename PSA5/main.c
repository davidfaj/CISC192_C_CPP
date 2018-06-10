/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA5
 Student        : David
 Description	: Using only C, create a program that will encrypt the character array "Hello!" using the Rotation 13 algorithm. The character manipulation must be done using only pointers. Display the encrypted string on the console. Next, decrypt the array and display it on the console. I have prepared a starter project, PSA 5, that will help you get started. You may use it or not as you prefer. Note: what we are doing is trivial -- just adding and subtracting 13 to each character. However, there are plenty of places to get tripped up on this simple code! Take care to make sure pointers are set and reset at the appropriate places.Also note that nearly everything (the only exception is the ++ operator) is what we done in the last two PSAs.
 ============================================================================
 */

#include <stdio.h>  // Standard I/O library
//#include <stdlib.h>

int main() {

    char plainText[] = "Hello!\n";  // The plain text to encrypt.
    char encryptedText[80];         // The encrypted array, not initialized!
    char decryptedText[80];         // The decrypted array, not initialized!

    char *ppt;                      // Pointer to the plain text.
    char *pen;                      // Pointer to the encrypted text.
    char *pde;                      // Pointer to the decrypted text.

    ppt = &plainText[0];            // Assign the address of the plain text to the plain text pointer.

    printf("The plain text is: %s",ppt); //Display it on the console.

    /*****************************
    *  YOUR CODE GOES HERE       *
    *****************************/

    // Encrypt the character array "Hello!" using the Rotation 13 algorithm using only pointers
    pen = &encryptedText[0];    // assign the address of encryptedText[0] to its pointer pen
    int i;	// declares variable i to work as a counter to loop through the whole plain text
    int numChars = 5;	// plain text "Hello!" has 6 characters (0 to 5)
    for(i = 0; i <= numChars; i++){
        *pen = *ppt + 13;   // encrypts each character by adding 13 to it
        pen++;  // moves the encrypted text pointer to one memory up
        ppt++;  // moves the plain text pointer to one memory up
    }
    *pen = '\0';    // As printf() prints the char array until it finds a null, I added this null ('\0') in the address just after the last character encrypted was set

    // Display the encrypted string on the console
    printf("The encrypted text is: %s\n", encryptedText);

    // Decrypt the array
    pen = &encryptedText[0];    // assign the address of encryptedText[0] to its pointer pen again, as the previous commands pen++ moved the pointer address up
    pde = &decryptedText[0];    // assign the address of decryptedText[0] to its pointer pde
    for(i = 0; i <= numChars; i++){
        *pde = *pen - 13;   // decrypts each character by adding 13 to it
        pde++;  // moves the decrypted text pointer to one memory up
        pen++;  // moves the encrypted text pointer to one memory up
    }
    *pde = '\0';    // As printf() prints the char array until it finds a null, I added this null ('\0') in the address just after the last character decrypted was set

    // Display the array on the console
    printf("The decrypted text is: %s\n", decryptedText);

    return 0;
}
