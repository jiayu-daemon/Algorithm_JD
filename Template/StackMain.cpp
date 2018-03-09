#include <iostream>
#include "Stack.h"

using namespace std;


template <typename T>
void testStack(
	Stack <T> &theStack,//
	T value,
	T increment,
	const string stackName
	)
{
	cout << "\nPushing element onto " << stackName << '\n';

	// push
	while(theStack.push(value))
	{
		cout << value << ' ';
		value += increment;
	}

	cout << "Stack is full. Cannot push\nPoping element from " << stackName << '\n';

	// pop
	while(theStack.pop(value))
	{
		cout << value << ' ';
	}

	cout << "Stack is empty. Cannot pop" << endl;

}



int main()
{
	// Stack<double> doubleStack(5);
	// double doubleValue = 1.1;

	// cout << "Push element onto doubleStack\n";
	// while(doubleStack.push(doubleValue)){
	// 	cout << doubleValue << ' ';
	// 	doubleValue += 1.1;
	// }

	// cout << "Poping element from doubleStack\n";

	// while(doubleStack.pop(doubleValue)){
	// 	cout << doubleValue << ' ';
	// }

	// cout << "Stack is empty , push / pop OK" <<endl;

	Stack<double> doubleStack(5);
	Stack<int> intStack;

	testStack(doubleStack,1.1, 1.1,"doubleStack");
	testStack(intStack,1,1,"intStack");


	return 0;
}