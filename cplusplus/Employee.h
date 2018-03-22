#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;


class Employee
{
public:
	Employee(const string &, const string &);
	~Employee(); // destructor

	string getFirstName() const; // return first name
	string getLastName() const;  // return last name

	//static member function
	static int getCount(); // return number of objects instantiated
private:
	string firstName;
	string lastName;
	// static data 
	static int count; // number of objects instantiated
}; // end class Employee



#endif
