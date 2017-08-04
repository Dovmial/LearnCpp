#include <iostream>
#include "mergeSort.h"
using std::cout;
using std::endl;

int main()
{
	MergeSort sortVector(10);
	cout << "Unsorted vector:" << endl;
	sortVector.displayElements();
	cout << endl << endl;
	sortVector.sort();
	cout << "Sorted vector:\n";
	sortVector.displayElements();
	cout << endl;
	return 0;
}