#include <iostream>
#include "Time1.h"

using namespace std;

int main()
{
	Time t; //create Time Object
	// cascaded fuction calls
	t.setHour(18).setMinute(30).setSecond(22);

	// output time in universal and standard formats
	cout << "universal time:";
	t.printUniversal();

	cout << "\nStandard time:";
	t.printStandard();

	cout << "\n\nNew standard time:";
	t.setTime(20,20,20).printStandard();

	cout << endl;
}


