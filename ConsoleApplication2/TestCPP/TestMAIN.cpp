#include <iostream>
using std::cout;
using std::endl;
#include <exception>
using std::exception;
void throwException()
{
	try
	{
		cout << "Function theowException throws an exception\n";
		throw exception();
	}
	catch (exception &)
	{
		cout << "  Exception handled in function trowException"
			<< "\n  Function throwException rethrows exception";
		throw;
	}
}
int main()
{
	try
	{
		cout << "\nmain invokes function throwException\n";
		throwException();
		cout << "This should not print\n";
	}
	catch(exception &)
	{
		cout << "\n\nException handled in main\n";
	}
	cout << "Programm control continue after catch in main\n";
	return 0;
}