#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;


template < typename NODETYPE >
class List
{
public:
	List();
	~List();

	void insertAtFront(const NODETYPE &);
	void insertAtBack(const NODETYPE &);
	bool removeFromFront(NODETYPE &);
	bool removeFromBack(NODETYPE &);

	bool isEmpty() const;
	void print() const;

private:
	ListNode < NODETYPE > * firstPtr; // pointer to first node
	ListNode < NODETYPE > * lastPtr; // pointer to last node

	// utility function to allocate new node
	ListNode < NODETYPE > * getNewNode (const NODETYPE &);

};  // end class List


//default constructor 
template < typename NODETYPE >
List < NODETYPE >::List()
	:firstPtr(0), lastPtr(0)
{
	//empty body
} //end list constructor


//destructor
template <typename NODETYPE>
List <NODETYPE>::~List()
{
	cout << "Destroying nodes ...\n";
	if(!isEmpty()) // List is not empty
	{
		ListNode < NODETYPE > *currentPtr = firstPtr;
		ListNode <NODETYPE> *tempPtr;

		while(currentPtr != 0)
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}// end while
	}
}

// insert node at front of list
template <typename NODETYPE>
void List < NODETYPE >::insertAtFront(const NODETYPE &value)
{
	ListNode <NODETYPE> *newPtr = getNewNode(value); 

	if(isEmpty())
		firstPtr = lastPtr = newPtr;
	else{
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}

// insert node at back of list
template <typename NODETYPE>
void List <NODETYPE>::insertAtBack(const NODETYPE & value)
{
	ListNode <NODETYPE> *newPtr = getNewNode(value); 

	if(isEmpty())
		firstPtr = lastPtr = newPtr;
	else{
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	}
}

//delete node from front of list
template <typename NODETYPE>
bool List< NODETYPE >::removeFromFront(NODETYPE & value)
{
	if(isEmpty())
		return false;
	else{
		ListNode <NODETYPE > * tempPtr = firstPtr; // hold temPtr to delete

		if(firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->nextPtr;
		value = tempPtr->data;
		delete tempPtr;

		return true;
	}
}

// delete node from back of list
template <typename NODETYPE>
bool List <NODETYPE>::removeFromBack(NODETYPE & value)
{
	if(isEmpty())
		return false;
	else{
		ListNode<NODETYPE> * tempPtr = lastPtr;

		if(firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
		{
			ListNode <NODETYPE> * currentPtr = firstPtr;

			// locate sencond to last element
			while(currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr; //
			lastPtr = currentPtr;
			currentPtr->nextPtr = 0; 
		}

		value = tempPtr->data;
		delete tempPtr;

		return true;
	}
}


template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	return firstPtr == 0;
}


// allocated node
template <typename NODETYPE>
ListNode <NODETYPE> *List<NODETYPE> ::getNewNode(const NODETYPE &value)
{
	return new ListNode < NODETYPE >(value);
}

// display
template <typename NODETYPE>
void List <NODETYPE>::print() const
{
	if(isEmpty())
	{
		cout << "The List is empty\n\n";
		return;
	}

	ListNode <NODETYPE> * currentPtr = firstPtr;
	cout << "The List is: ";

	while(currentPtr != 0){
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	}
	cout << "\n\n";
}

#endif