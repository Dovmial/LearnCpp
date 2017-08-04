// MyExecRefsDll.cpp
// compile with: /EHsc /link MathFuncsDll.lib

#include <iostream>

#include "MathFuncsDll.h"

using std::cout;
using std::endl;
using namespace MathFuncs;
int main()
{
	double a = 7.4;
	int b = 99;

	/*cout << "a + b = " <<
		MyMathFuncs::Add(a, b) << endl;
	cout << "a - b = " <<
		MyMathFuncs::Subtract(a, b) << endl;
	cout << "a * b = " <<
		MyMathFuncs::Multiply(a, b) << endl;*/
	cout << "a / b = " <<
		MyMathFuncs::Divide(a, b) << endl;

	try
	{
		cout << "a / 0 = " <<
			MyMathFuncs::Divide(a, 0) << endl;
	}
	catch (const std::invalid_argument &e)
	{
		cout << "Caught exception: " << e.what() << endl;
	}
	getchar();
	return 0;
}