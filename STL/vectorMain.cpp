#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector <T> & intergers2);


int main()
{
	const int SIZE = 6;
	int array[SIZE] = {1,2,3,4,5,6};

	vector <int > intergers;
	cout << "The initial size of intergers is :" << intergers.size()
	<< "\nThe initial capacity of integers is " << intergers.capacity();

	intergers.push_back(2);
	intergers.push_back(3);
	intergers.push_back(4);

	cout << "\nThe size of integers is:" << intergers.size()
	<< "\nThe capacity of integers is:" << intergers.capacity();
	cout << "\n\nOutput array using pointer notation";

}
