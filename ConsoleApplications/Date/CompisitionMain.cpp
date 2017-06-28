#include<iostream>
#include"Employee.h"
using std::cout;
using std::endl;

int main()
{
	cout << "Number of employees before creation of any objects is "
		<< Employee::getCount << endl;
	Employee *e1Ptr = new Employee ("Susan", "Baker");
	Employee * e2Ptr = new Employee ("Robert", "Jones");
	cout << "Number of employees after objects are instantiated is "
		<< e1Ptr->getCount();
	cout << "\n\nEmployee 1: "
		<< e1Ptr->getFirstName() << ' ' << e1Ptr->getLastName()
		<< "\nEmployee 2: " << e2Ptr->getFirstName()
		<< ' ' << e2Ptr->getLastName() << "\n\n";

	delete e1Ptr;
	e1Ptr = 0;
	delete e2Ptr;
	e2Ptr = 0;
	cout << "Number of employees after objects are deleted is "
		<< Employee::getCount << endl;
	return 0;
}