// Fig 
// Employee class member-function class definitions.

#include <iostream>
#include "Employee.h"

using namespace std;

// define and initialize static data member at global namespace scope
int Employee::count = 0; // cannot include keyword static

int Employee::getCount()
{
	return count;
}

//constuctor initializes non-staitc data members and 
Employee::Employee(const string & first, const string & last):firstName(first),lastName(last)
{
	++count; // increment static count of employees
	cout << "Employee constuctor for" << firstName
	<< ' ' << lastName << " called." << endl;
}


//destuctor deallocates dynamically allocated memory
Employee::~Employee()
{
	cout << "~Employee() called for " << firstName << ' ' << lastName << endl;
	--count; 
}


string Employee::getFirstName() const
{
	return firstName;
}

string Employee::getLastName() const
{
	return lastName;
}