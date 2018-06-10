/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA10
 Student        : David
 Date submitted	: 4/4/2017
 Description	: This is an improvement of the Auto Part Store inventory system
  	  	  	  	  to makes use of C++ features. It adds a command line interface
  	  	  	  	  (CLI) to the previous code. We will add a total of three
  	  	  	  	  commands. The first two are add and display. These correspond to
  	  	  	  	  the functions that are already defined. The third function is
  	  	  	  	  exit -- this should break the command loop and exit the program.
  	  	  	  	  The command loop should report illegal commands and invalid parts
  	  	  	  	  type.
 Logic used		: 1) The CLI runs continuously due to a loop, while the "running"
  	  	  	  	  is true.
  	  	  	  	  2) Display instructions to the user and show a command prompt
  	  	  	  	  3) Get the user input, according to this logic: the first word is
  	  	  	  	  assigned to the 'command' variable. If the user types a space
  	  	  	  	  after the command, save everything after the command to the
  	  	  	  	  variable 'part'. Go to the next step after user type a newline.
  	  	  	  	  4) Using if-else, check if the command exists. If the command
  	  	  	  	  doesn't exist, show an error message. If it exists, then:
  	  	  	  	  4a) if 'exit': change 'running' to false to exit the loop
  	  	  	  	  4b) if 'help': display some help
  	  	  	  	  4c) if 'display': display inventory.
  	  	  	  	  4d) if 'add': check if 'part' is found in the available part
  	  	  	  	  names inside warehouse1 and set 'partExists' to true or false. If
  	  	  	  	  it doesn't exist, display error message. If it exists, add a new
  	  	  	  	  part to the inventory.
 ============================================================================
 */

/* Warehouse stocking program -- Part 2.                      */
/* This program implements an inventory program such as would */
/* normally be found in an auto parts store.                  */

/* C code.
#include <stdio.h>
#include <stdlib.h>
*/

#define STRINGSIZE 20 // Size of all of the character arrays.
                      // Not used at the moment.

#include <iostream>
#include <string>

using namespace std;

// The enumerated list of parts. Note the last enum is SIZE.
enum partType {WRENCH, TIRE, BATTERY, SPARKPLUG, SIZE};

// This is basic structure for the database.
struct stock
{
    /* C code: char partName[STRINGSIZE]; */
    string partName;
    int partNumber;
    double price;
    int partsInStock;
    int partsOnOrder;
};

// Function Prototypes
int init(struct stock *warehouse); // Initializes the data base.
int addPart(int partNumber,struct stock *); // Adds a part to the inventory.
int stringcopy(char *pc1, char *pc2); // String copy function (local).
void displayAll(struct stock *warehouse);

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

/***************************************************/
//        The command loop should go here.
/*
 * CODE WRITTEN BY DAVID - BEGIN
 */

    // Start the CLI by setting "running" as true
    bool running = true;

    // Display initial instructions
    cout << " *** AUTOPARTS SYSTEM ***" << endl;
    cout << "  Commands available: add, display, exit, help" << endl << endl;

    // Declare variables
    string command;		// save the user command (first word, before the first space or newline)
    string part;		// save the auto-part (second word, after the space after the command)
    bool partExists;	// true (exists) or false (don't exist)


    // Main loop to keep CLI running, wait for user commands and execute them
    while(running) {
    	// Prompt the user
    	cout << "command: ";
    	// Get the command
    	cin >> command;
    	//  If the user haven't typed a newline, get the part name
    	if(cin.get() != '\n')
    		getline(cin, part);

    	// If the user command is 'exit'
    	if(command.compare("exit") == 0)
    		running = false;

    	// Else If the user command is 'help'
    	else if(command.compare("help") == 0) {
    		cout << "Help instructions:" << endl;
    		cout << "Type 'help': see the commands available" << endl;
    		cout << "Type 'exit': exit the system"<< endl;
    		cout << "Type 'display': display the inventory " << endl;
    		cout << "Type 'add <auto-part name>': add a part to the inventory" << endl;
    		cout << "Auto-parts available to add (case sensitive!): ";
    		// Loop in enum to list the auto parts names
    		for (int index = 0; index < SIZE; index++ )
    			cout << warehouse1[index].partName << " (part number " << warehouse1[index].partNumber << ")" << " / ";
    		cout << endl;
    	}

    	// Else If the user command is 'display'
    	else if(command.compare("display") == 0)
    		displayAll(warehouse1);

    	// Else If the user command is 'add'
    	else if(command.compare("add") == 0) {
            partExists = false;
    		// Check if the part name is valid (if exists in warehouse1.partName's)
            for (int index = 0; index < SIZE; index++ ) {
                if(part.compare(warehouse1[index].partName) == 0) {
                	partExists = true;
                    // Add part to warehouse
                    addPart(warehouse1[index].partNumber, warehouse1);
                    cout << "Added part " << part << endl;
                }
            }
            // If part doesn't exist, display error message
            if(!partExists)
                cout << part << " is not a valid part. Type 'help' to check the available parts." << endl;
    	}

    	// Else If the user type any other commands, display error message
    	else
    		cout << "This is not a valid command, type 'help' to see the available commands." << endl;

    }

/*
 * CODE WRITTEN BY DAVID - END
 */
/***************************************************/
    //displayAll(warehouse1);

    cout << "Thanks for using this inventory system." << endl;
    return 0;
}

// Initializes the data base.
int init(struct stock warehouse[])
{
    /* C code.
        int index = 0;
        int error = 0;
    */

    // Note the local instantiation of index.
    for (int index = 0; index < SIZE; index++ )
    {
        warehouse[index].partName[0] = '\0';
        warehouse[index].partNumber = 0;
        warehouse[index].price = 0;
        warehouse[index].partsInStock = 0;
        warehouse[index].partsOnOrder = 0;
    }

    warehouse[WRENCH].partNumber = WRENCH;
    /* C code.
    error = stringcopy(warehouse[WRENCH].partName, &"Wrench");
    */
    warehouse[WRENCH].partName = "Wrench"; // Using a string!

    warehouse[TIRE].partNumber = TIRE;
    warehouse[TIRE].partName = "Tire";

    warehouse[BATTERY].partNumber = BATTERY;
    warehouse[BATTERY].partName = "Battery";

    warehouse[SPARKPLUG].partNumber = SPARKPLUG;
    warehouse[SPARKPLUG].partName = "Spark Plug";

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

void displayAll(struct stock warehouse[])
{
    // For the entire database.
    for (int index = 0; index < SIZE; index++ )
    {
        cout << "Name: " << warehouse[index].partName << endl;
        cout << "Number: " << warehouse[index].partNumber << endl;
        cout << "Price: " << warehouse[index].price << endl;
        cout << "Stock: " << warehouse[index].partsInStock << endl;
        cout << "On Order: " << warehouse[index].partsOnOrder << endl << endl;
    }
}

// Not used now.
int stringcopy(char *pc1, char *pc2)
{
    int count = 0;

    // Copy the characters. If longer than STRINGSIZE return an error.
    while ((*pc1++ = *pc2++))
        if (count++ > STRINGSIZE ) return -1;

    return 0; // String copy completed without an error.
}
