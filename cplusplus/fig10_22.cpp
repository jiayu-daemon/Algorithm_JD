#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
	// no object exitst; use class name and binary scope resolution
	// operator to access static member fuction getCount

	cout << "Number of employees before instantiation of any objects is "<< Employee::getCount() << endl;   

	// use class name
	// the following scope create and destroys
	// Employee objects before main terminates
	{
		Employee e1("Susan", "Baker");
		Employee e2("Robert", "Jones");

		// two objects exist; call static member function getCount again
		// using the class name and the binary scope resolution operator
		cout << "Number of employees after objects are instantiated is" << Employee::getCount();

		cout << "\n\nEmpoyee 1:"
		<< e1.getFirstName() << " " << e1.getLastName()
		<< "\nEmployee 2:"
		<< e2.getFirstName() << " " << e2.getLastName() << "\n\n";
	}

	cout << "\nNumber of employees after objects are deleted is " << Employee::getCount() << endl;

}

/*
lim@ubuntu11204:/mnt/hgfs/personalDir/Algorithm_JD/cplusplus$ 

./Employee Number of employees before instantiation of any objects is 0


Employee constuctor forSusan Baker called.
Employee constuctor forRobert Jones called.
Number of employees after objects are instantiated is2

Empoyee 1:Susan Baker
Employee 2:Robert Jones

~Employee() called for Robert Jones
~Employee() called for Susan Baker

Number of employees after objects are deleted is 0
*/