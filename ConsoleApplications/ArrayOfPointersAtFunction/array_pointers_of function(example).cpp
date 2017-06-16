#include<iostream>
using std::cout;
using std::cin;
using std::endl;


void function0(int);
void function1(int);
void function2(int);

int main()
{
	void(*f[3])(int) = { function0,function1,function2 };
	int choice;
	cout << "Enter a number between 0 & 2, 3 to end: ";
	cin>>choice;
	while ((choice >= 0) && (choice < 3))
	{
		(*f[choice])(choice);
		cout << "Enter a number between 0 & 2, to end: ";
		cin >> choice;
	}
	cout << "Programm execution completed." << endl;
	return 0;
}

void function0(int a)
{
	cout << "You entered " << a << " so function0 was called\n\n";
}
void function1(int b)
{
	cout << "You entered " << b << " so function1 was called\n\n";
}
void function2(int c)
{
	cout << "You entered " << c << " so function2 was called\n\n";
}
