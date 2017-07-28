#include <iostream>
#include "TemplClass.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

template<typename T>void testStack(
	Stack<T> &theStack, T value, T increment,
	const string stackName)
{
	cout << "Pushing elements onto "<< stackName<<endl;
	while (theStack.push(value))
	{
		cout << value << ' ';
		value += increment;
	}
	cout << "\nStack is full. Cannot push " << value
		<< "\n\nPopping elemenst from "<<stackName<<'\n';
	while (theStack.pop(value))
		cout << value << ' ';
	cout << "\nStack is empty. Cannot pop\n";
}

int main()
{
	Stack <double>doubleStack(5);
	Stack<int>intStack;

	testStack(doubleStack, 1.1, 1.1, "doubleStack");
	testStack(intStack, 1, 1, "intStack");
	return 0;
}