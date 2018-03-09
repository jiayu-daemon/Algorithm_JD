#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack(int = 10); // default constructor(Stack size 10)
	// destructor
	~Stack()
	{
		delete [] stackPtr;
	}
	bool push(const T&);
	bool pop(T &);

	bool isEmpty() const
	{
		return top == -1;
	}

	bool isFull() const
	{
		return top == size -1;
	}
private:
	int size;
	int top;
	T * stackPtr;
};


// constructor template
template <typename T>
Stack< T >::Stack(int s)
	:size(s > 0?s:10),
	top(-1),
	stackPtr(new T[size])
{
	// empty body
}

//push element onto Stack;
//if success ,return true; otherwise, return false
template<typename T>
bool Stack< T >::push(const T & pushValue)
{
	if(!isFull())
	{
		stackPtr[++top] = pushValue; // place item on Stack
		return true;
	}

	return false;
}

// pop element off Stack;
// if success, return true; otherwise, return false
template <typename T>
bool Stack< T >::pop(T & pushValue)
{
	if(!isEmpty())
	{
		pushValue = stackPtr[top--]; // remove item from Stack
		return true;
	}

	return false;
}

#endif