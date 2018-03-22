#include <iostream>

using namespace std;

class Test
{
public:
	Test(int = 0); // default constructor
	void print() const;
private:
	int x;
};

Test::Test(int value):x(value) // initialize x to value
{
	//empty
}


// print x using implicit and explicit this pointers;
// the parentheses around *this are required
void Test::print() const
{
	// implictly use this pointer to access the member x
	cout << " x = " << x;

	// explicitly use the this pointer and arrow operator
	// to access the member x
	cout << "\n this->x = " << this->x;

	// explicitly use dereferenced this pointer and 
	// the dot operator to access the member x
	cout << "\n(*this).x = " << (*this).x << endl;
}


int main()
{
	Test testObject(12);
	testObject.print();
}