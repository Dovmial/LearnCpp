#include <cstring>
#include<iostream>
#include "Date.h"
#include "Employee.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

int Employee::count = 0;
int Employee::getCount()
{
	return count;
}
Employee::Employee(const char*const first, const char*const last)
{
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);
	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);
	count++;
	cout << "Employee object constructor: "
		<< firstName << ' ' << lastName << endl;
}


Employee::~Employee()
{
	cout << "Employee called for "
		<< firstName << ", " <<lastName  << endl;
	delete[] firstName;
	delete[] lastName;
	count--;
}
const char *Employee::getFirstName()const
{
	return firstName;
}

const char *Employee::getLastName()const
{
	return lastName;
}