#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout << "Enter two integers:";
	
	//Create istream_iterator for reading int values from cin
	istream_iterator <int> inputInt(cin);

	int number1 = *inputInt; // read int from standard input
	++inputInt;
	int number2 = *inputInt; // read int from standard input
	
	//create ostream_iterator for writing in values to cout
	ostream_iterator <int> outputInt(cout);
	
	cout << "The sum is:";
	*outputInt = number1 + number2; // output result to cout
	cout << endl;
	
	return 0;
}
