// This program demonstrates the use of string stream.

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream stringExample;

    string name;

    stringExample << "Bob 33.7 250"; // String to be processed.
    stringExample >> name;       // Extract "Bob".

    double x;
    stringExample >> x;          // Convert "33.7" to a double.

    int y;
    stringExample >> y;          // Convert "250" to an integer.

    cout << "Name: " << name << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    // Convert an integer to a hex string.
    stringstream working;
    working << "0x" << uppercase << hex << y;
    string value;
    working >> value;
    cout << "The value of y in hex is: " << value << endl;

    return 0;
}
