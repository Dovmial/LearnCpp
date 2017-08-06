#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Queue.h"

//template<typename T>
//void testList(List<T>&listObject, const string &typeName)
//{
//	cout << "Testing a List of " << typeName << " values\n";
//	instructions();
//	int choice;
//	T value;
//	do
//	{
//		cout << "? ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Enter " << typeName << ": ";
//			cin >> value;
//			listObject.insertAtFront(value);
//			listObject.print();
//			break;
//		case 2:
//			cout << "Enter " << typeName << ": ";
//			cin >> value;
//			listObject.insertAtBack(value);
//			listObject.print();
//			break;
//		case 3:
//			if (listObject.removeFromFront(value))
//				cout << value << " removed from list\n";
//
//			listObject.print();
//			break;
//		case 4:
//			if (listObject.removeFromBack(value))
//				cout << value << " removed from list\n";
//
//			listObject.print();
//			break;
//		}
//	} while (choice != 5);
//	cout << "End list test\n\n";
//}
//
//void instructions()
//{
//	cout << "Enter one of the following:\n"
//		<< "  1 to insert at begginning of list\n"
//		<< "  2 to insert at end of list\n"
//		<< "  3 to delete from begginning of list\n"
//		<< "  4 to delete from end of list\n"
//		<< "  5 to end list processing\n";
//}

int main()
{
	Queue<int>intQueue;
	cout << "processing an integer Queue" << endl;
	for (int i = 0; i < 3; i++)
	{
		intQueue.enqueue(i);
		intQueue.printQueue();
	}
	int dequeueInteger;
	while (!intQueue.isQueueEmpty())
	{
		intQueue.dequeue(dequeueInteger);
		cout << dequeueInteger << "dequeued" << endl;
		intQueue.printQueue();
	}

	Queue<double>doubleQueue;
	double value = 1.1;
	cout << "processing a double Queue" << endl;
	for (int j = 0; j < 3; ++j)
	{
		doubleQueue.enqueue(value);
		doubleQueue.printQueue();
		value += 1.1;
	}

	double dequeueDouble;
	while (!doubleQueue.isQueueEmpty())
	{
		doubleQueue.dequeue(dequeueDouble);
		cout << dequeueDouble << "dequeued" << endl;
		doubleQueue.printQueue();
	}

	return 0;
}