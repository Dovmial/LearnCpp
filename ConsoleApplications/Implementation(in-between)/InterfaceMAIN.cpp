#include <iostream>
#include"Interface.h"
using std::cout;
using std::endl;

int main()
{
	Interface i(5);
	cout << "Interface contains: " << i.getValue()
		<< " before setValue" << endl;
	i.setValue(10);
	cout << "Interface contains: " << i.getValue()
		<< " after setValue" << endl;
	return 0;
}