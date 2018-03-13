#include <vector>
using namespace std;


class BinarySearch
{
public:
	BinarySearch (int); // constructor initializes vector
	int binarySearch (int) const; // perform a binary search on vector
	void displayElements() const; // display vector elements
private:
	int size; // vector size
	vector <int> data; // vector o ints
	void displaySubElements(int, int) const; // display range of value
};