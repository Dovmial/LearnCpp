#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "PhoneNumber.h"
int main()
{
	PhoneNumber phone;
	cout << "Enter phone number in form (123) 456-7890:" << endl;
	cin >> phone;
	cout << "The phone number entered was: ";
	cout << phone << endl;
	return 0;
}

