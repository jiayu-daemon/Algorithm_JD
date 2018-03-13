#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "BinarySearch.h"


using namespace std;

// constructor initializes vector with random ints and sorts the vector
BinarySearch::BinarySearch(int vectorSize)
{
	size = (vectorSize > 0? vectorSize:10); // 
	srand(time(0)); // seed using current time

	// fill vector with random ints in range 10-99
	for(int i = 0; i < size; i++)
		data.push_back(10 + rand() % 90);

	std::sort(data.begin(),data.end()); // sort the data
}


//perform a binary search on the data
int BinarySearch::binarySearch(int searchElement) const
{
	int low = 0;
	int high = size - 1;
	int middle = (low + high + 1 ) /2; // 
	int location = -1;

	do // loop to search for element
	{
		// print remaining elements of vector to be searched
		displaySubElements(low, high);

		// output spaces for aligment
		for (int i = 0; i < middle; i++)
			cout << " ";
		cout << "*" << endl;

		// if the element is found at the middle
		if(searchElement == data[middle])
			location = middle;
		else if(searchElement < data[middle])
			high = middle - 1;
		else
			low = middle + 1;

		middle = (low + high +1) / 2;

	}while( (low <= high) && (location == -1) );

	return location;
}


// display values in vector
void BinarySearch::displayElements() const
{
	displaySubElements(0,size -1);
} // end function displayElements


// display certain values in vector
void BinarySearch::displaySubElements(int low, int high) const
{
	for(int i = 0; i < low; i++)
		cout << " ";
	for(int i = low; i <= high; i++)
		cout << data[i] << " ";
	cout << endl;
}// end function displaySubElements





