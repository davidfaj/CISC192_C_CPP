/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA9
 Student        : David
 Date submitted	: 3/22/2017
 Description	: Your first assignment is to write a program that displays all of the inventory and the associated information: price, quantities, etc.
 ============================================================================
 */

/* Warehouse stocking program -- Part 1                       */
/* This program implements an inventory program such as would */
/* normally be found in an auto parts store.                  */

#include <stdio.h>
#include <stdlib.h>

#define STRINGSIZE 20 // Size of all of the character arrays.

// The enumerated list of parts. Note the last enum is SIZE.
enum partType {WRENCH, TIRE, BATTERY, SPARKPLUG, SIZE};

// This is basic structure for the database.
struct stock
{
    char partName[STRINGSIZE];
    int partNumber;
    double price;
    int partsInStock;
    int partsOnOrder;
};

int init(struct stock *); // Initializes the data base.
int addPart(int partNumber,struct stock *); // Adds a part to the inventory.
int stringcopy(char *pc1, char *pc2); // String copy function (local).
/* CODE ADDED BY DAVID - BEGIN
*/
void displayInv();   // display the inventory and the associated information: price, quantities, etc.
/* CODE ADDED BY DAVID - END
*/

int main()
{
    struct stock warehouse1[SIZE]; // Create the database.

    init (warehouse1); // Initialize the relevant data base.

    addPart(TIRE, warehouse1); // Check some tires into the inventory.
    addPart(TIRE, warehouse1);
    addPart(TIRE, warehouse1);

    addPart(BATTERY, warehouse1); // Check some batteries into the inventory.
    addPart(BATTERY, warehouse1);
    addPart(BATTERY, warehouse1);
    addPart(BATTERY, warehouse1);

    /* CODE ADDED BY DAVID - BEGIN
    */
    // Display the inventory
    displayInv(warehouse1);
    /* CODE ADDED BY DAVID - END
    */

    printf("Thanks for using this inventory system.\n");
    return 0;
}

// Initializes the data base.
int init(struct stock warehouse[])
{
    int index = 0;
    int error = 0;

    for (index = 0; index < SIZE; index++ )
    {
        warehouse[index].partName[0] = '\0';
        warehouse[index].partNumber = 0;
        warehouse[index].price = 0;
        warehouse[index].partsInStock = 0;
        warehouse[index].partsOnOrder = 0;
    }

    warehouse[WRENCH].partNumber = WRENCH;
    error = stringcopy(warehouse[WRENCH].partName, &"Wrench");

    warehouse[TIRE].partNumber = TIRE;
    error = stringcopy(warehouse[TIRE].partName, &"Tire");

    warehouse[BATTERY].partNumber = BATTERY;
    error = stringcopy(warehouse[BATTERY].partName, &"Battery");

    warehouse[SPARKPLUG].partNumber = SPARKPLUG;
    error = stringcopy(warehouse[SPARKPLUG].partName, &"Spark Plug");

    return 0;
}

int addPart(int partNumber, struct stock warehouse[])
{
    int index;
    // Find the part in the database.
    for (index = 0; index < SIZE; index++ )
    {
        if (warehouse[index].partNumber == partNumber)
        {
            // Increment the count. We are done.
            warehouse[index].partsInStock++;
            return 0;
        }

    }
    return -1; // No such part in the database.
}

int stringcopy(char *pc1, char *pc2)
{
    int count = 0;

    // Copy the characters. If longer than STRINGSIZE return an error.
    while (*pc1++ = *pc2++)
        if (count++ > STRINGSIZE ) return -1;

    return 0; // String copy completed without an error.
}

/* CODE ADDED BY DAVID - BEGIN
*/

/** Method displayInv()
 *      Prints a report with the data in the warehouse[] in a table format
 * @param warehouse[]   pointer to a struct stock
 * @return void         doesn't return anything
*/
void displayInv(struct stock warehouse[]){
    // Print the header of the table
    printf(" -------------------------------------------------------------------------- \n");
    printf("| %-12s | %-12s | %-12s | %-12s | %-12s |\n", "PART NAME", "PART NUMBER", "PRICE", "QT. IN STOCK", "QT. ON ORDER");
    printf(" -------------------------------------------------------------------------- \n");
    // Loop to print each record of the table
    int index = 0;
    for (index = 0; index < SIZE; index++ ){
        // Print the record
        printf("| %-12s | %-12d | %-12.2lf | %-12d | %-12d |\n",
               warehouse[index].partName,
               warehouse[index].partNumber,
               warehouse[index].price,
               warehouse[index].partsInStock,
               warehouse[index].partsOnOrder);
        // Print a separator
        printf(" -------------------------------------------------------------------------- \n");
    }
    printf("\n");

}
/* CODE ADDED BY DAVID - END
*/
