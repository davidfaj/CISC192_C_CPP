/*
 ============================================================================
 Class          : CISC 192 - C/C++
 Assignment     : PSA11
 Student        : David
 Date submitted : 4/12/2017
 Description    : This is a continuation of the Auto Shop program. At start up,
    the program should read in the contents of a file that populates the database
    structure. On exit your program should save the contents of the database back
    to the file.
 Logic used     : (1) Before the CLI (console) runs, read "fileOut.txt" and save
     the data inside it to the database (warehouse1 struct). Then run the CLI as    usual, let users add more parts. When the user exits the CLI, just before
    exiting the program, read the database and output it to the "fileOut.txt". So,
    on the next time the program is opened, it will import the data with all the
    new parts added before.
                  (2) The text file keeps the database with each record on a
    separate line (separated by a \n), while each fields are separated by a space
    (' '). The last record doesn't contain a \n after it, in order to not create
    a new line, which makes it easier to read the file later in a loop. The order
    that the fields appear in the file must be always the same!
 New stuff      : Included library fstream (deal with files)
 ============================================================================
 */


/* Warehouse stocking program -- Part 3.                      */
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
#include <fstream>


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


/*
 * Input the initial inventory from the text file - BEGIN
 */
    string filename = "./fileOut.txt";  // define a path and file name to input and output
    ifstream inputFile; // Instantiate the input file stream object.
    // Open the input file.
    inputFile.open(filename);
    // If the file could not be opend, display an error message
    if (!inputFile) {
        cerr << "The input file could not be opened.\n" << endl;
        cout << "(system: the database wasn't loaded with the text file)" << endl;
    }
    // Else if the file was opened, read the data inside it
    else {
        // Read in the data from the file while it doesn't reach the end of the file
        int index = 0;  // variables used as a database records counter
        while(!inputFile.eof()) {   // Loop through each line (record)
            // Read each field from the record and save in the database
            inputFile >> warehouse1[index].partNumber;
            inputFile >> warehouse1[index].price;
            inputFile >> warehouse1[index].partsInStock;
            inputFile >> warehouse1[index].partsOnOrder;
            inputFile.ignore(1, ' ');       // consume the last space character to read the part name (last field in the record)
            getline(inputFile, warehouse1[index].partName);
            index++;
        }

        inputFile.close();             // Always close the file when done!
        cout << "(system: the database was loaded with the text file)" << endl;
    }
/*
 * Input the initial inventory from the text file - END
 */


/***************************************************/
/*
 * RUN THE CLI (Command Line Interface) - BEGIN
 */

    // Start the CLI by setting "running" as true
    bool running = true;

    // Display initial instructions
    cout << " *** AUTOPARTS SYSTEM ***" << endl;
    cout << "  Commands available: add, display, exit, help" << endl << endl;

    // Declare variables
    string command;     // save the user command (first word, before the first space or newline)
    string part;        // save the auto-part (second word, after the space after the command)
    bool partExists;    // true (exists) or false (don't exist)


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
 * RUN THE CLI (Command Line Interface) - END
 */
/***************************************************/
    //displayAll(warehouse1);

    cout << "Thanks for using this inventory system." << endl;

/*
 * Output the final inventory to the text file - BEGIN
 */
    ofstream outputFile; // Instantiate the output file stream object.
    // Open the file.
    outputFile.open(filename);
    // If the file could not be opened, display an error message
    if (!outputFile) {
        cerr << "The output file could not be opened.\n" << endl;
        cout << "(system: the text file could not be loaded with the database)" << endl;
    }
    // Else if the file was opened, output the database data to the file
    else {
        // Write the entire database to a file
        // Loop through each record in the database
        for (int index = 0; index < SIZE; index++ )
        {
            // Output the each record to one line in the file separated by space
            outputFile << warehouse1[index].partNumber << " ";
            outputFile << warehouse1[index].price << " ";
            outputFile << warehouse1[index].partsInStock << " ";
            outputFile << warehouse1[index].partsOnOrder << " ";
            // When is the last record, don't put a newline after the part name
            if(index!=SIZE-1) {
                outputFile << warehouse1[index].partName << endl;
            }
            // For the other records, put a newline after the part name
            else {
                outputFile << warehouse1[index].partName;
            }
            /* PS: Just for curiosity, I tried to do this last if-else using a
             * ternary operator, to make it cleaner and only one line, but I
             * couldn't figure out. If you think that's possible, I would
             * appreciate if you can show me how to do it. Thanks!
             */
        }
        outputFile.close();             // Always close the file when done!
        cout << "(system: the text file was loaded with the database)" << endl;
    }
/*
 * Output the final inventory to the text file - END
 */

    // Exit the system
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

