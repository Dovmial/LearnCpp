#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "ArrayClass.h"
void outputArray(const Array &);
int main()
{
	Array integers1(7);
	outputArray(integers1);
	outputArray(3);
	return 0;
}
void outputArray(const Array &arrayToOutput)
{
	cout << "The Array received has " << arrayToOutput.getSize()
		<< " elements. The contents are:\n" << arrayToOutput << endl;
}