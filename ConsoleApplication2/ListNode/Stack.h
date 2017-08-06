#ifndef STACK_H
#define STACK_H
#include "List.h"
template<typename STACKTYPE>
class Stack
{
public:
	void push(const STACKTYPE& data)
	{
		stackList.insertAtFront(data);
	}
	bool pop(STACKTYPE &data)
	{
		return stackList.removeFromFront(data);
	}
	bool isStackEmpty()const
	{
		return stackList.isEmpty();
	}
	void printStack()const
	{
		stackList.print();
	}
private:
	//composition
	List<STACKTYPE>stackList;
};
#endif // !STACK_H

