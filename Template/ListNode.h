//Template ListNode Class definition
#ifndef LISTNODE_H
#define LISTNODE_H


//先定义
template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{

	friend class List < NODETYPE >; // make list friend
public:
	ListNode (const NODETYPE &); // constructor
	NODETYPE getData() const; // return data in node

private:
	NODETYPE data; // data
	ListNode < NODETYPE > *nextPtr; // next node in list

};// end class ListNode


//constructor
template <typename NODETYPE>
ListNode < NODETYPE >::ListNode(const NODETYPE &info)
	:data(info),nextPtr(0)
{
	//empty
}//end ListNode constructor



//return copy of data in node
template <typename NODETYPE>
NODETYPE ListNode < NODETYPE >::getData() const
{
	return data;
}//end function getData


#endif