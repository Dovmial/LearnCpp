#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template<typename QUEUETYPE>
class Queue : private List<QUEUETYPE>
{
public:
	void enqueue(const QUEUETYPE & data)
	{
		insertAtBack(data);
	}

	bool dequeue(QUEUETYPE & data)
	{
		return removeFromFront(data);
	}
	bool isQueueEmpty()const
	{
		return isEmpty();
	}
	void printQueue()const
	{
		print();
	}
};
#endif // !QUEUE_H

