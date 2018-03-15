#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main()
{
    int searchInt;
    int position;

    BinarySearch searchVector(15);
    searchVector.displayElements();

    // get input from user
    cout << "\nPlease enter an integer value (-1 to quit)";
    cin >> searchInt; // read an int form user 
    cout << endl;

    // repeated input an integer; -1 terminates the program
    while(searchInt != -1){
        // use binary search to try to find integer
        position = searchVector.binarySearch(searchInt);

        // return value of -1 indicates integer was not found
        if(position == -1)
            cout << "The integer" << searchInt << "was not found .\n";
        else
            cout << "The integer" << searchInt << " was found in position " << position << ".\n";

        // get input from user
        cout << "\n\nPlease enter an integer value (-1 to quit)";
        cin >> searchInt;
        cout << endl;
    }
}
