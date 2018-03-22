/*

*/
#include <iostream>

using namespace std;

class Count
{
public:
	void setX(int value){
		x = value;
	}
	void print(){
		cout << x << endl;
	}
private:
	int x;
};



int main()
{
	Count counter;
	Count * counterPtr = &counter;
	Count & counterRef = counter;

	cout << "Set x to 1 and print using the object's name:";
	counter.setX(1);
	counter.print();

	cout << "Set x to 2 and print using a reference to an object:";
	counterRef.setX(2);
	counterRef.print();

	cout << "Set x to 3 and print using a pointer to an object:";
	counterPtr->setX(3);
	counterPtr->print();

	return 0;
}




