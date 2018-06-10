/*
 ============================================================================
 Class			: CISC 192 - C/C++
 Assignment		: PSA7
 Student        : David
 Date submitted	: 3/8/2017
 Description	: This program counts the total number of characters in a string and then counts the number of times each individual letter occurs. The output should be display as shown in the attached image.
 Extra comments : The steps of the program (or pseudocode) are the comments inside main(), each line comment is a step. The comments to the right of a line of code, gives more details about that specific code.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

// Set variable message with a text inside
char message[] = "Now the trumpet summons us again--not as a call to bear arms,\n\
though arms we need--not as a call to battle, though embattled we are-- but\n\
a call to bear the burden of a long twilight struggle, year in and year out,\n\
rejoicing in hope, patient in tribulation --a struggle against the common\n\
enemies of man: tyranny, poverty, disease and war itself.\n\
Can we forge against these enemies a grand and global alliance, \n\
North and South, East and West, that can assure a more fruitful life\n\
for all mankind? Will you join in that historic effort? \n\n\
In the long history of the world,\n\
only a few generations have been granted the role of defending\n\
freedom in its hour of maximum danger.\n\
I do not shrink from this responsibility--I welcome it.\n\
I do not believe that any of us would exchange places with any other\n\
people or any other generation. The energy, the faith, the devotion\n\
which we bring to this endeavor will light our country and all who serve it\n\
--and the glow from that fire can truly light the world.\n\
And so, my fellow Americans: ask not what your country can do for you\n\
--ask what you can do for your country.\n";

    // Set variables
    int totalCharacters;        // total characters in message
    int charCount[26];          // characters in the alphabet
    int index = 0;              // index of each character in the alphabet
    int position = 0;           // position of each character in the message
    int maxoccurence = 0;       // maximum occurrence of a character

    char temp = '\0';

    printf("%s",message);

    totalCharacters = sizeof(message)/sizeof(char);                             // calculate the number of characters, dividing size in bytes of message by size of a char in bytes, so you have the number of chars
    printf("\n\nThe total number of characters is: %d\n\n", totalCharacters);

    for (index = 0; index < 26; index++) charCount[index] = 0;                  // assign 0 to each character in the alphabet counter

    /*****************************************************/
    /**********  Your code goes here  ********************/
    /*****************************************************/

    for(position = 0; position < totalCharacters; position++)                                           // Loop through each letter of the message
        for(index = 0; index < 26; index++)                                                             // Loop through each letter of the alphabet
            if((message[position] == (index + 'A')) || (message[position] == (index + 'A' + 32)))       // Check if the letter of the message is equals to the letter of the alphabet (capitalized or not capitalized). The idea of adding 32 is the offset in the ASCII Table of 'A' (65) to 'a' (97)
                charCount[index]++;                                                                     // if so, adds one to the counter of that specific letter

    // Print the output of each letter of the alphabet and its respective counter
    for (index = 0; index < 26; index++) printf("char %c : %d\n", (index+65), charCount[index]);


    /*****************************************************/
    /**********  Teacher code below   ********************/
    /*****************************************************/

    // Loop through each letter of the alphabet counter. If maxoccurrence is smaller than the previous counters, assign it to that counter
    for (index = 0; index < 26; index++)
        if (maxoccurence < charCount[index])
            maxoccurence = charCount[index];

    printf("\nThe letter used most often occurs: %d times.\n",maxoccurence);

    // Get the letter most used by looking for the maxoccurence in each letter of the alphabet counter
    for (index = 0; index < 26; index++)
        if (maxoccurence == charCount[index]) temp = 'A' + index;

    printf("\nThe letter used most often is: %c\n",temp);

    return 0;
}
